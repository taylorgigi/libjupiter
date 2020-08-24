//
// Created by taylor on 2020/8/24.
//

#ifndef JUPITER_LOGGER_H
#define JUPITER_LOGGER_H

#include <memory>
#include <spdlog/spdlog.h>

namespace jupiter
{
    extern std::shared_ptr<spdlog::logger> logger;

    //@brief                    init logger
    //@param    logger_name     name of the logger which will be created
    //@param    dir             directory name, which should be a name, neither absolute path nor relative path
    //@param    log_name        file name of log file, which is a prefix of log file
    //@return                   abort while failed
    void logger_init(const char *logger_name, const char *dir, const char *log_name);
} // namespace jupiter

#endif //JUPITER_LOGGER_H
