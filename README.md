# MineOJ-Judger

## 使用的第三方库：

- [AMQP-CPP](https://github.com/CopernicaMarketingSoftware/AMQP-CPP)
- [libev](http://software.schmorp.de/pkg/libev.html)
- [jsoncpp](https://github.com/open-source-parsers/jsoncpp)

## 安装依赖

### AMQP-CPP

```sh
wget https://github.com/CopernicaMarketingSoftware/AMQP-CPP/archive/v2.8.0.zip
unzip v2.8.0.zip
cd v2.8.0
make && sudo make install
```

### libev

```sh
wget http://dist.schmorp.de/libev/libev-4.24.tar.gz
unzip libev-4.24.tar.gz
cd libev-4.24
./configure && make && make install
```
### jsoncpp

无需安装。
