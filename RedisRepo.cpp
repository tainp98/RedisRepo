#include "RedisRepo.h"

RedisRepo::RedisRepo()
{
    //redis = Redis("tcp://127.0.0.1:6379");
}



string RedisRepo::encodeMatToString(cv::Mat &mat){
    std::stringstream ss;
    if (!mat.empty()) {
        try {
            std::vector<uint8_t> buffer;
            cv::imencode(".jpg", mat, buffer);
            for (auto c : buffer) ss << c;
        } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    }
    return ss.str();
}

void RedisRepo::pushToList(cv::Mat& mat){
    string mat_string = encodeMatToString(mat);
    getRedis().lpush("facelist1", mat_string);
}

cv::Mat RedisRepo::removeAndGetMat(){

    std::vector<std::string> res;
    getRedis().lrange("facelist1", 0, 0, std::back_inserter(res));
    getRedis().blpop("facelist1");
    //auto a = getFromList();
    std::vector<uint8_t> data(res[0].begin(), res[0].end());
    cv::Mat mat(data, true);
    mat = cv::imdecode(mat, cv::IMREAD_UNCHANGED);
    return mat;
}


