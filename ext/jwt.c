
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "jwt.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *jwt_exception_domainexception_ce;
zend_class_entry *jwt_exception_jsonexception_ce;
zend_class_entry *jwt_token_ce;
zend_class_entry *jwt_utils_ce;

ZEND_DECLARE_MODULE_GLOBALS(jwt)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(jwt)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Jwt_Exception_DomainException);
	ZEPHIR_INIT(Jwt_Exception_JsonException);
	ZEPHIR_INIT(Jwt_Token);
	ZEPHIR_INIT(Jwt_Utils);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(jwt)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_jwt_globals *jwt_globals TSRMLS_DC)
{
	jwt_globals->initialized = 0;

	/* Memory options */
	jwt_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	jwt_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	jwt_globals->cache_enabled = 1;

	/* Recursive Lock */
	jwt_globals->recursive_lock = 0;

	/* Static cache */
	memset(jwt_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_jwt_globals *jwt_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(jwt)
{
	zend_jwt_globals *jwt_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	jwt_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(jwt_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(jwt_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Jwt_Token(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(jwt)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(jwt)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_JWT_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_JWT_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_JWT_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_JWT_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_JWT_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(jwt)
{
	php_zephir_init_globals(jwt_globals TSRMLS_CC);
	php_zephir_init_module_globals(jwt_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(jwt)
{
	
}


zend_function_entry php_jwt_functions[] = {
	ZEND_FE_END

};

zend_module_entry jwt_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_JWT_EXTNAME,
	php_jwt_functions,
	PHP_MINIT(jwt),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(jwt),
#else
	NULL,
#endif
	PHP_RINIT(jwt),
	PHP_RSHUTDOWN(jwt),
	PHP_MINFO(jwt),
	PHP_JWT_VERSION,
	ZEND_MODULE_GLOBALS(jwt),
	PHP_GINIT(jwt),
	PHP_GSHUTDOWN(jwt),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(jwt),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_JWT
ZEND_GET_MODULE(jwt)
#endif
