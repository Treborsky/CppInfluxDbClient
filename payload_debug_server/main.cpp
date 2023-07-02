/* PayloadDebugServer - software for debug TCP payload visualisation
 *
 * AUTHOR: Robert Koziarski (https://github.com/Treborsky)
 * USE ALLOWED UNDER MIT LICENSE.
 *
 * Functionality: Starts a localhost TCP server accepting connections on
 * specified port. Displays the payload contained in the TCP message to STDOUT.
 * Created for debugging HTTP requests sent from CppInfluxDbClient application.
 *
 * Usage: ./PayloadDebugServer <port>
 *
 */

#include <iostream>
#include <sockpp/tcp_acceptor.h>
#include <sockpp/version.h>
#include <thread>

void handle_incoming_tcp_connection(sockpp::tcp_socket sock) {
  ssize_t n;
  char buf[512];

  while ((n = sock.read(buf, sizeof(buf))) > 0) {
    sock.write_n(buf, n);
    std::cout << "Payload received: " << buf << std::endl;
  }

  std::cout << "Connection closed from " << sock.peer_address() << std::endl;
}

int main(int argc, char *argv[]) {
  std::cout << "PayloadDebugServer - TCP Payload visualisation client - Robert "
               "Koziarski 2023 (https://github.com/Treborsky)"
            << '\n'
            << "using sockcpp(https://github.com/fpagliughi/sockpp) "
            << sockpp::SOCKPP_VERSION << '\n'
            << std::endl;

  in_port_t port = (argc > 1) ? atoi(argv[1]) : 12345;

  sockpp::initialize();

  sockpp::tcp_acceptor acceptor(port);

  if (!acceptor) {
    std::cerr << "Error creating the acceptor: " << acceptor.last_error_str()
              << std::endl;
    return 1;
  }
  std::cout << "Awaiting connections on port " << port << "..." << std::endl;

  while (true) {
    sockpp::inet_address peer;

    sockpp::tcp_socket socket = acceptor.accept(&peer);
    std::cout << "Received a connection request from " << peer << std::endl;

    if (!socket) {
      std::cerr << "Error accepting incoming connection: "
                << acceptor.last_error_str() << std::endl;
    } else {
      std::thread incoming_connection_handler_thread(
          handle_incoming_tcp_connection, std::move(socket));
      incoming_connection_handler_thread.detach();
    }
  }

  return 0;
}
