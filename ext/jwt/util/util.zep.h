
extern zend_class_entry *jwt_util_util_ce;

ZEPHIR_INIT_CLASS(Jwt_Util_Util);

PHP_METHOD(Jwt_Util_Util, test);

ZEPHIR_INIT_FUNCS(jwt_util_util_method_entry) {
	PHP_ME(Jwt_Util_Util, test, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
