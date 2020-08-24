//
// Created by taylor on 2020/8/24.
//

#include "backtrace.h"
#include <boost/filesystem.hpp>
#include <cstdlib>
#include <cstdio>
#include "Logger.h"
#include "Mutex.h"
#include <pthread.h>
#include <string>

namespace jupiter
{
    namespace {
        Mutex mutex_;
        std::string logger_name_;
        std::string dir_;
        std::string log_name_;

        pthread_once_t logger_is_initialized = PTHREAD_ONCE_INIT;
    }

    std::shared_ptr<spdlog::logger> logger;

    void logger_init_()
    {
        boost::filesystem::path cur_path = boost::filesystem::current_path();
        cur_path.append("/");
        cur_path.append(dir_);
        if (!boost::filesystem::exists(cur_path)) {
            if (!boost::filesystem::create_directory(cur_path)) {
                printf("create log dir failed: %s", cur_path.c_str());
                BACKTRACE();
                abort();
            }
        }
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_async_mode(8192, spdlog::async_overflow_policy::block_retry, nullptr, std::chrono::milliseconds(1000));
        char buf[128] = {0};
        sprintf(buf, "%s/%s", cur_path.c_str(), log_name_.c_str());
        logger = spdlog::hourly_logger_mt(logger_name_, buf, 5 * 1024 * 1024);
        logger->set_pattern("[%Y-%m-%d %T.%e]: %v");
    }

    void logger_init(const char *logger_name, const char *dir, const char *log_name)
    {
        {
            MutexGuard guard(mutex_);
            if(logger_name_.empty() && dir_.empty() && log_name_.empty()) {
                logger_name_ = logger_name;
                dir_ = dir;
                log_name_ = log_name;
            }
        }
        pthread_once(&logger_is_initialized, &logger_init_);
    }

} // namespace jupiter

