
extern zend_class_entry *jwt_exception_jsonexception_ce;

ZEPHIR_INIT_CLASS(Jwt_Exception_JsonException);

PHP_METHOD(Jwt_Exception_JsonException, __construct);
zend_object *zephir_init_properties_Jwt_Exception_JsonException(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jwt_exception_jsonexception___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jwt_exception_jsonexception_method_entry) {
	PHP_ME(Jwt_Exception_JsonException, __construct, arginfo_jwt_exception_jsonexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
