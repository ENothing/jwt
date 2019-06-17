namespace Jwt;

class Utils
{
   public static function safeStrlen(var str){

        return mb_strlen(str,"8bit");

   }

   public static function urlsafeB64Encode(var input){

       return str_replace("=", "", strtr(base64_encode(input), "+/", "-_"));

   }

    public static function urlsafeB64Decode(var input){

        var remainder;
        let remainder = strlen(input) % 4;

        if remainder {

            var padlen;
            let padlen = 4 - remainder;
            let input = input . str_repeat("=", padlen);

        }

        return base64_decode(strtr(input, "-_", "+/"));

    }

}