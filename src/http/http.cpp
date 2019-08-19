#include "http.h"
#include <iostream>
#include <string>
//#include "../vendor/httplib.h"
#include "../vendor/HTTPRequest.h"

// HTTP Request to get package info
void getPackageInfo(std::string repoBaseUrl) {
//    httplib::Client cli("www.httpvshttps.com");
//
//    auto res = cli.Get("/");
//    if (res && res->status == 200) {
//        std::cout << res->body;
//    } else {
//        std::cout << "Status Code: " << res->status;
//    }

    // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
    http::Request request("http://www.httpvshttps.com");

    // send a get request
    http::Response response = request.send("GET");
    std::cout << std::string(response.body.begin(), response.body.end()) << std::endl; // print the result
}
