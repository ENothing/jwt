
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Jwt_Exception_JsonException) {

	ZEPHIR_REGISTER_CLASS_EX(Jwt\\Exception, JsonException, jwt, exception_jsonexception, zend_exception_get_default(TSRMLS_C), jwt_exception_jsonexception_method_entry, 0);

	zend_declare_property_null(jwt_exception_jsonexception_ce, SL("_errors"), ZEND_ACC_PRIVATE TSRMLS_CC);

	jwt_exception_jsonexception_ce->create_object = zephir_init_properties_Jwt_Exception_JsonException;
	return SUCCESS;

}

PHP_METHOD(Jwt_Exception_JsonException, __construct) {

	zval message;
	zval *type_param = NULL, *code_param = NULL, *message_param = NULL, value, _0, _2, _1$$3;
	zend_long type, code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&message);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &type_param, &code_param, &message_param);

	type = zephir_get_intval(type_param);
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "Unknow json error");
	} else {
		zephir_get_strval(&message, message_param);
	}


	ZEPHIR_OBS_VAR(&value);
	zephir_read_property(&_0, this_ptr, SL("_errors"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_long_fetch(&value, &_0, 1, 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, "json error:", &value);
		zephir_get_strval(&message, &_1$$3);
	}
	ZVAL_LONG(&_2, code);
	ZEPHIR_CALL_PARENT(NULL, jwt_exception_jsonexception_ce, getThis(), "__construct", NULL, 0, &message, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Jwt_Exception_JsonException(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_errors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 10, 0 TSRMLS_CC);
			add_index_stringl(&_1$$3, 1, SL("JSON_ERROR_DEPTH"));
			add_index_stringl(&_1$$3, 2, SL("JSON_ERROR_STATE_MISMATCH"));
			add_index_stringl(&_1$$3, 3, SL("JSON_ERROR_CTRL_CHAR"));
			add_index_stringl(&_1$$3, 4, SL("JSON_ERROR_SYNTAX"));
			add_index_stringl(&_1$$3, 5, SL("JSON_ERROR_UTF8"));
			add_index_stringl(&_1$$3, 6, SL("JSON_ERROR_RECURSION"));
			add_index_stringl(&_1$$3, 7, SL("JSON_ERROR_INF_OR_NAN"));
			add_index_stringl(&_1$$3, 8, SL("JSON_ERROR_UNSUPPORTED_TYPE"));
			add_index_stringl(&_1$$3, 9, SL("JSON_ERROR_INVALID_PROPERTY_NAME"));
			add_index_stringl(&_1$$3, 10, SL("JSON_ERROR_UTF16"));
			zephir_update_property_zval(this_ptr, SL("_errors"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

