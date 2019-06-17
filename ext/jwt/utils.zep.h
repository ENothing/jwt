
extern zend_class_entry *jwt_utils_ce;

ZEPHIR_INIT_CLASS(Jwt_Utils);

PHP_METHOD(Jwt_Utils, safeStrlen);
PHP_METHOD(Jwt_Utils, urlsafeB64Encode);
PHP_METHOD(Jwt_Utils, urlsafeB64Decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_utils_safestrlen, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_utils_urlsafeb64encode, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_utils_urlsafeb64decode, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jwt_utils_method_entry) {
	PHP_ME(Jwt_Utils, safeStrlen, arginfo_jwt_utils_safestrlen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Utils, urlsafeB64Encode, arginfo_jwt_utils_urlsafeb64encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Jwt_Utils, urlsafeB64Decode, arginfo_jwt_utils_urlsafeb64decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
