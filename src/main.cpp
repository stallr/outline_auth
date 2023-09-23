#include <fstream>
#include <iostream>

#include "HttpServer.h"
#include "json.h"

using namespace hv;
using namespace std;

int parseJsonToMap(const string &fileName, map<string, string> &data) {
    Json::Value root;
    Json::Reader reader;

    std::ifstream ifs(fileName, ios::binary);

    if (!reader.parse(ifs, root)) {
        cout << "JSON文件解析失败，请查看JSON文件路径或JSON配置是否有问题！" << endl;
        return -1;
    } else {
        std::cout << root << std::endl;
        data["domain"] = root["domain"].asString();
        data["s5_server"] = root["s5_server"].asString();
        return 0;
    }
}
int main(int, char **) {
    std::cout << "Hello, from outline_auth!\n";

    HttpService router;

    router.GET("/auth", [&router](HttpRequest *req, HttpResponse *resp) {
        string fileName = "../config.json";
        map<string, string> data;
        parseJsonToMap(fileName, data);
        return resp->Json(data);
    });

    HttpServer server;
    server.service = &router;
    server.port = 2020;

    server.run();

    return 0;
}
