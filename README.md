# RedisRepo
## I. Install Redis on ubuntu
### 1. install
$sudo apt-get update \
$sudo apt-get install redis-server\
### 2. start redis
$redis-server
### 3. check if redis is working
$redis-cli 

# redis-plusplus is the c++ client for redis that based on hiredis written in c
## II. Install hiredis
git clone https://github.com/redis/hiredis.git\
cd hiredis\
make\
make install\
--default installed folder is "/usr/local/include"

## III. Install redis-plusplus
git clone https://github.com/sewenew/redis-plus-plus.git\
cd redis-plus-plus\
mkdir build\
cd build\
cmake ..\
make\
make install\
cd ..\
--default installed folder is "/usr/local/include"

## IV. Use in Qt
INCLUDEPATH += /usr/local/include \
LIBS += -L/usr/local/lib -lhiredis -lredis++ -pthread 
