// clang-format off
#include "Timer.h" //include  #inlcude "headers.h"
#include "Lexer.h"
#include "Parser.h"
// clang-format on

static constexpr int numRuns = 50000;  // Number of runs for averaging
static constexpr std::string_view source = "42 + 17 / 2 ^ 3 - 3 % 4";

static void bencmark() {
    long double totalTokenizationTime = 0.0;
    std::stringstream sourcestr;
    sourcestr << source.data();

    for(size_t j = 0; j < 100; ++j) {
        Lexer lexers(sourcestr.str());
        for(int i = 0; i < numRuns; ++i) {
            Timer timer;
            std::vector<Token> tokens = lexers.getAllTokens();
            timer.stop();
#if WL_DEBUG
            totalTokenizationTime += timer.elapsedMicroseconds();
#else
            totalTokenizationTime += timer.elapsedNanoseconds();
#endif
        }
        std::size_t strleng = sourcestr.str().length();
        sourcestr << " + " << source;
        const long double averageTime = totalTokenizationTime / C_LD(numRuns);
#if WL_DEBUG
        LINFO(R"(Tokenize {:>4} chars: {:>10.6f} us avg, {:>8.6f} s for {} iteration)", strleng, averageTime,
              (totalTokenizationTime / 1000000), numRuns);
#else
        // LINFO(R"(Tokenize {:>4} chars: {:>11.6f} ns avg, {:>10.6f} ms for {} iteration)", strleng, averageTime,
        // (totalTokenizationTime / 1000000), numRuns);
        LINFO(R"(Tokenize {:>4} chars: {:>9.6f} us avg, {:>10.6f} ms for {} iteration)", strleng, (averageTime / 1000),
              (totalTokenizationTime / 1000000), numRuns);
#endif
    }
}

int main() {
    spdlog::set_pattern(R"(%^[%T] [%l] %v%$)");
    const auto console = spdlog::stdout_color_mt(R"(console)");
    spdlog::set_default_logger(console);
    bencmark();
    Lexer lexer(source.data());
    Timer timer;
    std::vector<Token> tokens = lexer.getAllTokens();
    timer.stop();
#if WL_DEBUG
    timer.elapsedMcsToString("lexing");
#else
    timer.elapsedNsToString("lexing");
#endif  // WL_DEBUG
    Timer tt;
    std::stringstream tokenss;
    for(const Token &t : tokens) {
        if(t.getType() == TokType::T_ERROR) {
            LCRITICAL("token invalido non ancora suportato: {}", t.getValue());
            exit(-1);
        }
        tokenss << t.toString() << "\n";
    }
    tt.stop();
    std::cout << tokenss.str();
#if WL_DEBUG
    tt.elapsedMcsToString("printing");
#else
    tt.elapsedNsToString("printing");
#endif  // WL_DEBUG
    SYSPAUSE()
    return 0;
}
