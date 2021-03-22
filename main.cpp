#include <iostream>
#include <sw/redis++/redis++.h>
#include<unordered_set>
#include <opencv2/opencv.hpp>
#include <typeinfo>

#include "RedisRepo.h"

int main()
{
    try {
        RedisRepo Re;
        cv::Mat img = cv::imread("/home/tainp/Downloads/orange.jpg", 1);
        Re.pushToList(img);
        cv::Mat mat = Re.removeAndGetMat();
        cv::imshow("mat1", mat);
        cv::waitKey();


        // Write elements in STL container to Redis
//        redis.rpush("list", {"a", "b", "c"});

//        std::vector<std::string> vec = {"d", "e", "f"};
//        redis.rpush("list", vec.begin(), vec.end());

//        // Write elements in Redis list to STL container
//        std::vector<std::string> res;
//        redis.lrange("list", 0, -1, std::back_inserter(res));
//        for(int i = 0; i < res.size(); i++)
//            std::cout << res[i] << std::endl;
//        std::string val1 = "this binary safe string contains your binary data";
//        redis.set("key1", val1);

//        char *data = "pointer to your binary data";
//        size_t len = 100; // length of your binary data
//        redis.set("key2", StringView(data, 100));
//        auto reply = redis.get("key2");
//        std::cout << *reply << std::endl;

        //redis.set("images", StringView(&img, img.size));
    } catch (const Error &e) {
        // Error handling
    }
}

