namespace Jwt;

use Jwt\Exception\DomainException;
use Jwt\Exception\JsonException;
use Jwt\Exception\InvalidArgumentException;
use Jwt\Exception\TokenException;

class Token
{
    public static leeway = 0;

    public static timestamp = null;

    private static algs = [
        "HS256":["hash_hmac","SHA256"],
        "HS384":["hash_hmac","SHA384"],
        "HS512":["hash_hmac","SHA512"],
        "RS256":["openssl","SHA256"],
        "RS384":["openssl","SHA384"],
        "RS512":["openssl","SHA512"]
    ];

    public static function test(var str){

        return Utils::urlsafeB64Decode(str);

    }

    public static function encode(var payload,var key,string alg = "HS256",var keyId = null,var head = null){
        array header = [];
        let header = [
            "typ":"JWT",
            "alg":alg
        ];
        if keyId !== null {
            let header["kid"] = keyId;
        }
        if !empty head && is_array(head) {
            let header = header->merge(head);
        }
        array segments = [];
        let segments[] = Utils::urlsafeB64Encode(self::jsonEncode(header));
        let segments[] = Utils::urlsafeB64Encode(self::jsonEncode(payload));
        var signing_input;
        let signing_input = implode(".",segments);

        var signature;
        let signature = self::sign(signing_input,key,alg);
        let segments[] = Utils::urlsafeB64Encode(signature);

        return implode(".",segments);
    }

    public static function decode(var jwt,var key,array allowed_algs = []){
        var timestamp;
        if is_null(self::timestamp) {
            let timestamp = time();
        }else{
            let timestamp = self::timestamp;
        }

        if empty key {
            throw new InvalidArgumentException("Key must not be empty");
        }
        var token;
        let token = explode(".",jwt);
        if count(token) != 3{
            throw new TokenException("Wrong token");
        }

        var header;
        let header = self::jsonDecode(Utils::urlsafeB64Decode(token[0]));
        if null === header {
            throw new TokenException("Invalid header encoding");
        }
        var payload;
        let payload = self::jsonDecode(Utils::urlsafeB64Decode(token[1]));
        if null === payload {
            throw new TokenException("Invalid claims encoding");
        }
        var sig;
        let sig = Utils::urlsafeB64Decode(token[2]);
        if false === sig {
            throw new TokenException("Invalid signature encoding");
        }
        if empty header->alg{
            throw new TokenException("Empty algorithm");
        }
        if !isset self::algs[header->alg] {
            throw new TokenException("Algorithm not supported");
        }
        if !in_array(header->alg,allowed_algs){
            throw new TokenException("Algorithm not allowed");
        }
        if is_array(key){
            if isset header->kid{
                if !isset key[header->kid]{
                    throw new TokenException("kid nvalid, unable to lookup correct key");
                }
                let key = key[header->kid];
            }else{
                throw new TokenException("kid empty, unable to lookup correct key");
            }
        }

        if self::verify(token[0].token[1],sig,key,header->alg){
            throw new TokenException("Signature verification failed");
        }

        if isset payload->nbf && payload->nbf > (timestamp + self::leeway){
            throw new TokenException("Cannot handle token nbf -- ".payload->nbf);
        }

        if isset payload->iat && payload->iat > (timestamp + self::leeway){
            throw new TokenException("Cannot handle token iat -- ".payload->iat);
        }
        if isset payload->exp && payload->exp < (timestamp - self::leeway){
            throw new TokenException("Token expired");
        }

        return payload;
    }

     public static function jsonEncode(var input){
         var json;
         let json = json_encode(input);
         if json_last_error() !== 0{

            throw new JsonException(json_last_error());

         }elseif json === null && input !== null {

            throw new DomainException("Null result with non-null input");

         }
         return json;
     }


     public static function jsonDecode(var input)
     {
          var obj;
          let obj = json_decode(input, false, 512, JSON_BIGINT_AS_STRING);
          if json_last_error() !== 0{

             throw new JsonException(json_last_error());

          }elseif obj === null && obj !== null {

             throw new DomainException("Null result with non-null input");

          }
          return obj;
     }

    public static function sign(var msg,var key,string alg = "HS256"){
        var value;
        if fetch value,self::algs[alg]{
            switch value[0] {
                case "hash_hmac":
                    return hash_hmac(value[1],msg,key,true);
                case "openssl":
                    var signature;
                    if !openssl_sign(msg,signature,key,value[1]) {
                        throw new DomainException("OpenSSL unable to sign data");
                    }
                    return signature;
                default :
                    throw new DomainException("Algorithm not supported");
            }
        }else{
            throw new DomainException("Algorithm not supported");
        }
    }

    private static function verify(var msg,var signature,var key,string alg){
        var value;
        if fetch value,self::algs[alg] {
            switch value[0] {
                case "hash_hmac":
                    var hash;
                    let hash = hash_hmac(value[1],msg,key,true);
                    return hash_equals(signature,Utils::safeStrlen(hash));
                case "openssl":
                    var verify;
                    let verify = openssl_verify(msg,signature,key,value[1]);
                    if verify === 1{
                        return true;
                    } elseif verify === 0{
                        return false;
                    }else{
                        throw new DomainException("Openssl errror: ".openssl_error_string());
                    }
                default:
                    throw new DomainException("Algorithm not supported");
            }

        }else{
            throw new DomainException("Algorithm not supported");
        }
    }

}