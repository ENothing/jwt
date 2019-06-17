namespace Jwt\Exception;

class JsonException extends \Exception
{

    private _errors = [
        1:"JSON_ERROR_DEPTH",
        2:"JSON_ERROR_STATE_MISMATCH",
        3:"JSON_ERROR_CTRL_CHAR",
        4:"JSON_ERROR_SYNTAX",
        5:"JSON_ERROR_UTF8",
        6:"JSON_ERROR_RECURSION",
        7:"JSON_ERROR_INF_OR_NAN",
        8:"JSON_ERROR_UNSUPPORTED_TYPE",
        9:"JSON_ERROR_INVALID_PROPERTY_NAME",
        10:"JSON_ERROR_UTF16"
    ];

    public function __construct(int type,int code = 0,string message = "Unknow json error"){
        var value;
        if fetch value, this->_errors[1] {
            let message = "json error:".value;
        }
        parent::__construct(message,code);
    }



}