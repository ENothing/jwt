
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Jwt_Util_Util) {

	ZEPHIR_REGISTER_CLASS(Jwt\\Util, Util, jwt, util_util, jwt_util_util_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Jwt_Util_Util, test) {

	zval *this_ptr = getThis();


	RETURN_STRING("hello world");

}

