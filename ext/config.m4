PHP_ARG_ENABLE(jwt, whether to enable jwt, [ --enable-jwt   Enable Jwt])

if test "$PHP_JWT" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, JWT_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_JWT, 1, [Whether you have Jwt])
	jwt_sources="jwt.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c jwt/exception/domainexception.zep.c
	jwt/exception/invalidargumentexception.zep.c
	jwt/exception/jsonexception.zep.c
	jwt/exception/tokenexception.zep.c
	jwt/token.zep.c
	jwt/utils.zep.c "
	PHP_NEW_EXTENSION(jwt, $jwt_sources, $ext_shared,, )
	PHP_SUBST(JWT_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([jwt], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([jwt], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/jwt], [php_JWT.h])

fi
