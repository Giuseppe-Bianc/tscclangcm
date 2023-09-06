#pragma once
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(push)
#pragma warning(disable : 6386 6385 4005 26481)
#endif
// clang-format off
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <execution>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numbers>
#include <omp.h>
#include <optional>
#include <random>
#include <ranges>
#include <string>
#include <set>
#include <spdlog/cfg/env.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <string_view>
#include <unordered_set>
#include <memory_resource>
#include <vector>
// clang-format on

#include "casts.h"
// Restore warning levels.
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(pop)
#endif

#define LTRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define LDEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define LINFO(...) SPDLOG_INFO(__VA_ARGS__)
#define LWARN(...) SPDLOG_WARN(__VA_ARGS__)
#define LERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define LCRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)
#define SYSPAUSE()                                                                                                               \
    LINFO("Press enter to exit...");                                                                                             \
    std::cin.ignore();

static inline constexpr long double infinity = std::numeric_limits<long double>::infinity();
static inline constexpr long double pi = std::numbers::pi_v<long double>;
static inline constexpr long double twoPi = 2 * pi;
static inline constexpr long double halfPi = pi / 2;
// Dimensioni della finestra
static inline constexpr double ratioW = 16.0;
static inline constexpr double ratioH = 9.0;
static inline constexpr double aspect_ratio = ratioW / ratioH;
static inline constexpr int imageF = 80;
static inline constexpr int w = C_I(ratioW * imageF);
static inline constexpr int h = C_I(ratioH * imageF);
static inline constexpr std::size_t ST_w = C_ST(w);
static inline constexpr std::size_t ST_h = C_ST(h);
static inline constexpr double scale = 256.0;
static inline constexpr double invStHMinusOne = 1.0 / C_D(ST_h - 1);
static inline constexpr double invStWMinusOne = 1.0 / C_D(ST_w - 1);
static inline constexpr unsigned long long doublesize = sizeof(double);
