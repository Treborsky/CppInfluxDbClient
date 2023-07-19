# CppInfluxDbClient
A C++ library for performing InfluxDB data writes. Designed for InfluxDB v2.0 API.

## Development platform
 - Windows 11 - WSL Ubuntu 20.04

## Target platforms
 - Ubuntu 20.04

## Dependencies
 - CMake => 3.20
 - cpp-httplib
 - sockpp
 - OpenSSL

Dependencies can be found in the `libraries` directory. To use them, go into the library directory, build & install with CMake.

## Project structure
`cpp_influxdb_client` - main library development directory.  
`palyoad_debug_server` - quick implementation of a TCP server, used for HTTP request visualization.

## Project roadmap
```mermaid
flowchart LR
    step1(Hardcoded request) --> step2(Request builder)
    step2 --> step3(Design library API)
    step3 --> step4(?)
```

## Development, changelog

Don't expect rapid development. This is merely a project that has been on my mind for a long time. I haven't found a InfluxDB v2.0 compatible C++ API for writes, so I decided that I will try to make it work myself.

### 02.07.2023 - Project creation

---

Uploaded first version of a development client. This isn't really a library right now, I'm figuring out how to build a correct POST request that will be accepted by InfluxDB v2.0 API.  
In it's current form, the `CppInfluxDbClient` starts with cmd line arguments for API endpoint, builds a POST request based on sample request from InfluxDB API documentation website.

Next steps: 
 - work on the POST request, so that InfluxDB v2.0 will accept it and write the data into the database.
 - add the dependencies in `libraries` directory as submodules, instead of storing the entire repo.

### 19.07.2023 - Development environment and work on request body

---

#### Work done:
 - Added aliased for more convenient code building.
 - Updated the _payload_debug_server_ program for more readable output.
 - Updated default endpoint to free instance of influxdb (hopefully won't get abused, I know it's a terrible practice).
 - Updated libraries to be git submodules.

#### Summary:
 - Developers can now iterate more quickly by not having to write the cmake and make commands themselves.
 - The credentials for those InfluxDB POST requests are put into the source code. I do know this is __bad practice__ but it's so much faster to run it like this.

#### Next steps:
 - Fix the request bodies. Maybe write some tests? The payload debug server could be used for that.
 - I don't really know what else, this first point should be the priority. There are definitely a couple of problems to solve:
    - SSL connection failed problem
    - request body
