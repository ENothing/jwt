
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Jwt_Token) {

	ZEPHIR_REGISTER_CLASS(Jwt, Token, jwt, token, jwt_token_method_entry, 0);

	zend_declare_property_long(jwt_token_ce, SL("leeway"), 0, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(jwt_token_ce, SL("timestamp"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(jwt_token_ce, SL("algs"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Jwt_Token, test) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *str, str_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_RETURN_CALL_CE_STATIC(jwt_utils_ce, "urlsafeb64decode", &_0, 0, str);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Jwt_Token, encode) {

	zend_bool _1;
	zval header, segments;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval alg;
	zval *payload, payload_sub, *key, key_sub, *alg_param = NULL, *keyId = NULL, keyId_sub, *head = NULL, head_sub, __$null, _0, _3, _5, _6, _7, signing_input, signature, _8, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&keyId_sub);
	ZVAL_UNDEF(&head_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&signing_input);
	ZVAL_UNDEF(&signature);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&alg);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&segments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &payload, &key, &alg_param, &keyId, &head);

	if (!alg_param) {
		ZEPHIR_INIT_VAR(&alg);
		ZVAL_STRING(&alg, "HS256");
	} else {
		zephir_get_strval(&alg, alg_param);
	}
	if (!keyId) {
		keyId = &keyId_sub;
		keyId = &__$null;
	}
	if (!head) {
		head = &head_sub;
		head = &__$null;
	}


	ZEPHIR_INIT_VAR(&header);
	array_init(&header);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("typ"), SL("JWT"));
	zephir_array_update_string(&_0, SL("alg"), &alg, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&header, &_0);
	if (Z_TYPE_P(keyId) != IS_NULL) {
		zephir_array_update_string(&header, SL("kid"), keyId, PH_COPY | PH_SEPARATE);
	}
	_1 = !(ZEPHIR_IS_EMPTY(head));
	if (_1) {
		_1 = Z_TYPE_P(head) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fast_array_merge(&_2$$4, &header, head TSRMLS_CC);
		ZEPHIR_CPY_WRT(&header, &_2$$4);
	}
	ZEPHIR_INIT_VAR(&segments);
	array_init(&segments);
	ZEPHIR_CALL_SELF(&_5, "jsonencode", NULL, 0, &header);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_3, jwt_utils_ce, "urlsafeb64encode", &_4, 0, &_5);
	zephir_check_call_status();
	zephir_array_append(&segments, &_3, PH_SEPARATE, "jwt/Token.zep", 42);
	ZEPHIR_CALL_SELF(&_7, "jsonencode", NULL, 0, payload);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_6, jwt_utils_ce, "urlsafeb64encode", &_4, 0, &_7);
	zephir_check_call_status();
	zephir_array_append(&segments, &_6, PH_SEPARATE, "jwt/Token.zep", 43);
	ZEPHIR_INIT_VAR(&signing_input);
	zephir_fast_join_str(&signing_input, SL("."), &segments TSRMLS_CC);
	ZEPHIR_CALL_SELF(&signature, "sign", NULL, 0, &signing_input, key, &alg);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_8, jwt_utils_ce, "urlsafeb64encode", &_4, 0, &signature);
	zephir_check_call_status();
	zephir_array_append(&segments, &_8, PH_SEPARATE, "jwt/Token.zep", 49);
	zephir_fast_join_str(return_value, SL("."), &segments TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Jwt_Token, decode) {

	zend_bool _21, _28, _34;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_16 = NULL;
	zval allowed_algs;
	zval *jwt, jwt_sub, *key = NULL, key_sub, *allowed_algs_param = NULL, timestamp, _0, token, header, _2, _4, payload, _5, _6, sig, _7, _8, _9, _10, _11, _15, _17, _18, _19, _20, _22, _23, _24, _29, _30, _35, _36, _1$$4, _12$$14, _13$$14, _14$$14, _25$$18, _26$$18, _27$$18, _31$$19, _32$$19, _33$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&jwt_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&sig);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&allowed_algs);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &jwt, &key, &allowed_algs_param);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!allowed_algs_param) {
		ZEPHIR_INIT_VAR(&allowed_algs);
		array_init(&allowed_algs);
	} else {
		zephir_get_arrval(&allowed_algs, allowed_algs_param);
	}


	zephir_read_static_property_ce(&_0, jwt_token_ce, SL("timestamp"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&timestamp);
		zephir_time(&timestamp);
	} else {
		ZEPHIR_OBS_VAR(&_1$$4);
		zephir_read_static_property_ce(&_1$$4, jwt_token_ce, SL("timestamp"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&timestamp, &_1$$4);
	}
	if (ZEPHIR_IS_EMPTY(key)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_invalidargumentexception_ce, "Key must not be empty", "jwt/Token.zep", 63);
		return;
	}
	ZEPHIR_INIT_VAR(&token);
	zephir_fast_explode_str(&token, SL("."), jwt, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(&token TSRMLS_CC) != 3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Wrong token", "jwt/Token.zep", 68);
		return;
	}
	zephir_array_fetch_long(&_4, &token, 0, PH_NOISY | PH_READONLY, "jwt/Token.zep", 72 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_2, jwt_utils_ce, "urlsafeb64decode", &_3, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&header, "jsondecode", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&header) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Invalid header encoding", "jwt/Token.zep", 74);
		return;
	}
	zephir_array_fetch_long(&_6, &token, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 77 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_5, jwt_utils_ce, "urlsafeb64decode", &_3, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&payload, "jsondecode", NULL, 0, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&payload) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Invalid claims encoding", "jwt/Token.zep", 79);
		return;
	}
	zephir_array_fetch_long(&_7, &token, 2, PH_NOISY | PH_READONLY, "jwt/Token.zep", 82 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&sig, jwt_utils_ce, "urlsafeb64decode", &_3, 0, &_7);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&sig)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Invalid signature encoding", "jwt/Token.zep", 84);
		return;
	}
	zephir_read_property(&_8, &header, SL("alg"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_8)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Empty algorithm", "jwt/Token.zep", 87);
		return;
	}
	zephir_read_static_property_ce(&_9, jwt_token_ce, SL("algs"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, &header, SL("alg"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_9, &_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Algorithm not supported", "jwt/Token.zep", 90);
		return;
	}
	zephir_read_property(&_11, &header, SL("alg"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_fast_in_array(&_11, &allowed_algs TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Algorithm not allowed", "jwt/Token.zep", 93);
		return;
	}
	if (Z_TYPE_P(key) == IS_ARRAY) {
		if (zephir_isset_property(&header, SL("kid"))) {
			zephir_read_property(&_12$$14, &header, SL("kid"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(key, &_12$$14))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "kid nvalid, unable to lookup correct key", "jwt/Token.zep", 98);
				return;
			}
			ZEPHIR_OBS_VAR(&_14$$14);
			zephir_read_property(&_14$$14, &header, SL("kid"), PH_NOISY_CC);
			zephir_array_fetch(&_13$$14, key, &_14$$14, PH_NOISY | PH_READONLY, "jwt/Token.zep", 100 TSRMLS_CC);
			ZEPHIR_CPY_WRT(key, &_13$$14);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "kid empty, unable to lookup correct key", "jwt/Token.zep", 102);
			return;
		}
	}
	zephir_array_fetch_long(&_17, &token, 0, PH_NOISY | PH_READONLY, "jwt/Token.zep", 106 TSRMLS_CC);
	zephir_array_fetch_long(&_18, &token, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 106 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_VV(&_19, &_17, &_18);
	zephir_read_property(&_20, &header, SL("alg"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&_15, "verify", &_16, 1, &_19, &sig, key, &_20);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Signature verification failed", "jwt/Token.zep", 107);
		return;
	}
	_21 = zephir_isset_property(&payload, SL("nbf"));
	if (_21) {
		zephir_read_property(&_22, &payload, SL("nbf"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_23, jwt_token_ce, SL("leeway"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_24);
		zephir_add_function(&_24, &timestamp, &_23);
		_21 = ZEPHIR_GT(&_22, &_24);
	}
	if (_21) {
		ZEPHIR_INIT_VAR(&_25$$18);
		object_init_ex(&_25$$18, jwt_exception_tokenexception_ce);
		zephir_read_property(&_26$$18, &payload, SL("nbf"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_27$$18);
		ZEPHIR_CONCAT_SV(&_27$$18, "Cannot handle token nbf -- ", &_26$$18);
		ZEPHIR_CALL_METHOD(NULL, &_25$$18, "__construct", NULL, 2, &_27$$18);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_25$$18, "jwt/Token.zep", 111 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_28 = zephir_isset_property(&payload, SL("iat"));
	if (_28) {
		zephir_read_property(&_23, &payload, SL("iat"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_29, jwt_token_ce, SL("leeway"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_30);
		zephir_add_function(&_30, &timestamp, &_29);
		_28 = ZEPHIR_GT(&_23, &_30);
	}
	if (_28) {
		ZEPHIR_INIT_VAR(&_31$$19);
		object_init_ex(&_31$$19, jwt_exception_tokenexception_ce);
		zephir_read_property(&_32$$19, &payload, SL("iat"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_33$$19);
		ZEPHIR_CONCAT_SV(&_33$$19, "Cannot handle token iat -- ", &_32$$19);
		ZEPHIR_CALL_METHOD(NULL, &_31$$19, "__construct", NULL, 2, &_33$$19);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_31$$19, "jwt/Token.zep", 115 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_34 = zephir_isset_property(&payload, SL("exp"));
	if (_34) {
		zephir_read_property(&_29, &payload, SL("exp"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_35, jwt_token_ce, SL("leeway"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_36);
		zephir_sub_function(&_36, &timestamp, &_35);
		_34 = ZEPHIR_LT(&_29, &_36);
	}
	if (_34) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_tokenexception_ce, "Token expired", "jwt/Token.zep", 118);
		return;
	}
	RETURN_CCTOR(&payload);

}

PHP_METHOD(Jwt_Token, jsonEncode) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *input, input_sub, json, _0, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_INIT_VAR(&json);
	zephir_json_encode(&json, input, 0 );
	ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", &_1, 3);
	zephir_check_call_status();
	_2 = Z_TYPE_P(&json) == IS_NULL;
	if (_2) {
		_2 = Z_TYPE_P(input) != IS_NULL;
	}
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, jwt_exception_jsonexception_ce);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "json_last_error", &_1, 3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 4, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "jwt/Token.zep", 129 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Null result with non-null input", "jwt/Token.zep", 133);
		return;
	}
	RETURN_CCTOR(&json);

}

PHP_METHOD(Jwt_Token, jsonDecode) {

	zend_bool _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *input, input_sub, __$false, obj, _0, _1, _2, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZVAL_LONG(&_0, 512);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_INIT_VAR(&obj);
	zephir_json_decode(&obj, input, zephir_get_intval(&__$false) );
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", &_3, 3);
	zephir_check_call_status();
	_4 = Z_TYPE_P(&obj) == IS_NULL;
	if (_4) {
		_4 = Z_TYPE_P(&obj) != IS_NULL;
	}
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_2, 0)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, jwt_exception_jsonexception_ce);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "json_last_error", &_3, 3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 4, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "jwt/Token.zep", 146 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (_4) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Null result with non-null input", "jwt/Token.zep", 150);
		return;
	}
	RETURN_CCTOR(&obj);

}

PHP_METHOD(Jwt_Token, sign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval alg;
	zval *msg, msg_sub, *key, key_sub, *alg_param = NULL, __$true, value, _0, _1$$3, _2$$4, signature$$5, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&signature$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&alg);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &msg, &key, &alg_param);

	if (!alg_param) {
		ZEPHIR_INIT_VAR(&alg);
		ZVAL_STRING(&alg, "HS256");
	} else {
		zephir_get_strval(&alg, alg_param);
	}


	ZEPHIR_OBS_VAR(&value);
	zephir_read_static_property_ce(&_0, jwt_token_ce, SL("algs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &alg, 0 TSRMLS_CC)) {
		zephir_array_fetch_long(&_1$$3, &value, 0, PH_NOISY | PH_READONLY, "jwt/Token.zep", 159 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(&_1$$3, "hash_hmac")) {
				zephir_array_fetch_long(&_2$$4, &value, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 161 TSRMLS_CC);
				ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 5, &_2$$4, msg, key, &__$true);
				zephir_check_call_status();
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&_1$$3, "openssl")) {
				zephir_array_fetch_long(&_3$$5, &value, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 164 TSRMLS_CC);
				ZEPHIR_MAKE_REF(&signature$$5);
				ZEPHIR_CALL_FUNCTION(&_4$$5, "openssl_sign", NULL, 6, msg, &signature$$5, key, &_3$$5);
				ZEPHIR_UNREF(&signature$$5);
				zephir_check_call_status();
				if (!(zephir_is_true(&_4$$5))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "OpenSSL unable to sign data", "jwt/Token.zep", 165);
					return;
				}
				RETURN_CCTOR(&signature$$5);
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Algorithm not supported", "jwt/Token.zep", 169);
			return;
		} while(0);

	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Algorithm not supported", "jwt/Token.zep", 172);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Jwt_Token, verify) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval alg;
	zval *msg, msg_sub, *signature, signature_sub, *key, key_sub, *alg_param = NULL, __$true, value, _0, _1$$3, hash$$4, _2$$4, _3$$4, verify$$5, _5$$5, _6$$8, _7$$8, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg_sub);
	ZVAL_UNDEF(&signature_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&hash$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&verify$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&alg);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &msg, &signature, &key, &alg_param);

	zephir_get_strval(&alg, alg_param);


	ZEPHIR_OBS_VAR(&value);
	zephir_read_static_property_ce(&_0, jwt_token_ce, SL("algs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &alg, 0 TSRMLS_CC)) {
		zephir_array_fetch_long(&_1$$3, &value, 0, PH_NOISY | PH_READONLY, "jwt/Token.zep", 179 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(&_1$$3, "hash_hmac")) {
				zephir_array_fetch_long(&_2$$4, &value, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 182 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&hash$$4, "hash_hmac", NULL, 5, &_2$$4, msg, key, &__$true);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_3$$4, jwt_utils_ce, "safestrlen", &_4, 0, &hash$$4);
				zephir_check_call_status();
				RETURN_MM_BOOL(zephir_hash_equals(signature, &_3$$4));
			}
			if (ZEPHIR_IS_STRING(&_1$$3, "openssl")) {
				zephir_array_fetch_long(&_5$$5, &value, 1, PH_NOISY | PH_READONLY, "jwt/Token.zep", 186 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&verify$$5, "openssl_verify", NULL, 7, msg, signature, key, &_5$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&verify$$5, 1)) {
					RETURN_MM_BOOL(1);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&verify$$5, 0)) {
					RETURN_MM_BOOL(0);
				} else {
					ZEPHIR_INIT_VAR(&_6$$8);
					object_init_ex(&_6$$8, jwt_exception_domainexception_ce);
					ZEPHIR_CALL_FUNCTION(&_7$$8, "openssl_error_string", NULL, 8);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_8$$8);
					ZEPHIR_CONCAT_SV(&_8$$8, "Openssl errror: ", &_7$$8);
					ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 2, &_8$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$8, "jwt/Token.zep", 192 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Algorithm not supported", "jwt/Token.zep", 195);
			return;
		} while(0);

	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(jwt_exception_domainexception_ce, "Algorithm not supported", "jwt/Token.zep", 199);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Jwt_Token(TSRMLS_D) {

	zval _2;
	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "hash_hmac");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA256");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("HS256"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "hash_hmac");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA384");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("HS384"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "hash_hmac");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA512");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("HS512"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "openssl");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA256");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("RS256"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "openssl");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA384");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("RS384"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "openssl");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SHA512");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("RS512"), &_1, PH_COPY | PH_SEPARATE);
	zend_update_static_property(jwt_token_ce, ZEND_STRL("algs"), &_0);
	ZEPHIR_MM_RESTORE();

}

