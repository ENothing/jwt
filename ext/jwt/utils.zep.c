
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Jwt_Utils) {

	ZEPHIR_REGISTER_CLASS(Jwt, Utils, jwt, utils, jwt_utils_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Jwt_Utils, safeStrlen) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str, str_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "8bit");
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 9, str, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Jwt_Utils, urlsafeB64Encode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_CALL_FUNCTION(&_0, "base64_encode", NULL, 10, input);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-_");
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 11, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "=");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_str_replace(&_4, &_1, &_2, &_3 TSRMLS_CC);
	RETURN_CCTOR(&_4);

}

PHP_METHOD(Jwt_Utils, urlsafeB64Decode) {

	zend_long ZEPHIR_LAST_CALL_STATUS, remainder = 0, padlen$$3 = 0;
	zval *input = NULL, input_sub, _4, _5, _6, _0$$3, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);

	ZEPHIR_SEPARATE_PARAM(input);


	remainder = (long) (zephir_safe_mod_long_long(zephir_fast_strlen_ev(input), 4 TSRMLS_CC));
	if (remainder) {
		padlen$$3 = (4 - remainder);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "=");
		ZVAL_LONG(&_1$$3, padlen$$3);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "str_repeat", NULL, 12, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VV(&_3$$3, input, &_2$$3);
		ZEPHIR_CPY_WRT(input, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "-_");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "+/");
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 11, input, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 13, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

