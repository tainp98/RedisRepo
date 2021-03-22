#ifndef REDISREPO_H
#define REDISREPO_H
#include <iostream>
#include <opencv2/opencv.hpp>
#include <sw/redis++/redis++.h>
using namespace std;
using namespace sw::redis;

class RedisRepo
{
public:
    RedisRepo();
    void pushToList(cv::Mat& mat);
    auto getRedis() -> decltype(Redis("tcp://127.0.0.1:6379")){
        return Redis("tcp://127.0.0.1:6379");
    }
//    auto getFromList() -> decltype(getRedis().get("list1")){
//        return getRedis().get("list1");
//    }
    string encodeMatToString(cv::Mat& mat);
    cv::Mat removeAndGetMat();


private:
    //const static auto redis = 0;

};

#endif // REDISREPO_H
