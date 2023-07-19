/* CppInfluxDbCLient - example application for C++ InfluxDB v2 API
 *
 * AUTHOR: Robert Koziarski (https://github.com/Treborsky)
 * USE ALLOWED UNDER MIT LICENSE.
 *
 */
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

#include <iostream>

int main(int argc, char **argv) {
  std::cout << "CppInfluxDbClient - Robert Koziarski 2023 "
               "(https://github.com/Treborsky)"
            << '\n'
            // used library authors shoutout
            << "Used IP:" << '\n'
            << "cpp-httplib: https://github.com/yhirose/cpp-httplib"
            << std::endl;
  // print usage for example client
  std::cout << "usage: ./CppInfluxDbClient <address> <port>" << '\n'
            << "example: ./CppInfluxDbClient 127.0.0.1 12345" << '\n'
            << std::endl;

  // default HTTP endpoint
  std::string address{"https://eu-central-1-1.aws.cloud2.influxdata.com"};
  std::string port{"80"};

  // parse command line provided endpoint
  if (argc > 1) {
    for (int i = 0; i < argc; ++i) {
      switch (i) {
      case 0: {
        break;
      }
      case 1: {
        address = std::string{argv[i]};
      }
      case 2: {
        port = std::string{argv[i]};
      }
      default: {
        break;
      }
      }
    }
  }

  const std::string endpoint{address + std::string{":"} + port};
  std::cout << "Creating HTTP client on endpoint: " << endpoint << '\n'
            << std::endl;
  httplib::Client cli(endpoint);

  std::cout << "Sending POST request to server" << std::endl;
  httplib::Headers post_headers{
      {"Authorization Token",
       "6fgRs4NU_CCaqGGdJk1ZqlnZGKipPAN51vHem2pGCarjHIpAc_t6zUiRJs-"
       "nEUThrqdZOQw-FcgsODqPn0e65Q==="},
      {"Content-Type", "text/plain; charset=utf-8"},
      {"Accept", "application/json"}};

  const char payload[] =
      "airSensors,sensor_id=TLM0201 "
      "temperature=73.97038159354763,humidity=35.23103248356096,co=0."
      "48445310567793615 1630424257000000000";

  const std::string content_type{"text/plain"};

  std::string write_url{"/api/v2/write"};

  write_url += "?org=robert.koziarski@solarboat.agh.edu.pl&bucket=cpp-testing&"
               "precision=ns";

  httplib::Result res =
      cli.Post(write_url, post_headers, payload, content_type);

  if (res) {
    std::cout << "POST success:" << '\n'
              << "status: " << res->status << '\n'
              << "body: " << res->body << std::endl;
  } else {
    std::cout << "POST failure: " << res.error() << std::endl;
  }
}
