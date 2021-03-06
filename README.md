### System Requirements

To build it you need the following requirements:

* g++ >= 4.4/clang++ >= 3.x/vc++ 9
* gnu make 3.81 or later
* autoconf 2.31 or later
* automake 1.14 or later
* PHP development headers and tools

If you're using Ubuntu, you can install the required packages this way:

```
sudo apt-get update
sudo apt-get install git gcc make re2c php7 php7-json php7-dev libpcre3-dev
```

### Installation

You can build extension and install it like:

```
git clone https://gitee.com/EricNothing/jwt.git
cd ext
./install
```
Edit your `php.ini` file and add this line:
```
extension=jwt.so
```

Don't forget to restart your php-fpm:
```
sudo service php7-fpm restart
```


Example
-------
```php
<?php

$key = "example_key";
$token = array(
    "iss" => "http://example.org",
    "aud" => "http://example.com",
    "iat" => 1356999524,
    "nbf" => 1357000000
);

$jwt = JWT\Token::encode($token, $key);
$decoded = JWT\Token::decode($jwt, $key, ['HS256']);

print_r($decoded);

JWT\Token::$leeway = 60; // $leeway in seconds
$decoded = JWT\Token::decode($jwt, $key, ['HS256']);
```



### Reference
https://github.com/firebase/php-jwt