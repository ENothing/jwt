
extern zend_class_entry *jwt_token_ce;

ZEPHIR_INIT_CLASS(Jwt_Token);

PHP_METHOD(Jwt_Token, test);
PHP_METHOD(Jwt_Token, encode);
PHP_METHOD(Jwt_Token, decode);
PHP_METHOD(Jwt_Token, jsonEncode);
PHP_METHOD(Jwt_Token, jsonDecode);
PHP_METHOD(Jwt_Token, sign);
PHP_METHOD(Jwt_Token, verify);
void zephir_init_static_properties_Jwt_Token(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_test, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_encode, 0, 0, 2)
	ZEND_ARG_INFO(0, payload)
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, alg)
#endif
	ZEND_ARG_INFO(0, keyId)
	ZEND_ARG_INFO(0, head)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_decode, 0, 0, 2)
	ZEND_ARG_INFO(0, jwt)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, allowed_algs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_jsonencode, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_jsondecode, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_sign, 0, 0, 2)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, alg)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_token_verify, 0, 0, 4)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_INFO(0, signature)
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, alg)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jwt_token_method_entry) {
	PHP_ME(Jwt_Token, test, arginfo_jwt_token_test, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, encode, arginfo_jwt_token_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, decode, arginfo_jwt_token_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, jsonEncode, arginfo_jwt_token_jsonencode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, jsonDecode, arginfo_jwt_token_jsondecode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, sign, arginfo_jwt_token_sign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Token, verify, arginfo_jwt_token_verify, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
