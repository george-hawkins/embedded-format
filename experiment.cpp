#include <fmt/core.h>
#include <NamedType/named_type.hpp>

using Width = fluent::NamedType<int, struct WidthTag>;


int main() {
    const Width w{3};

    fmt::print("Hello, world! {}\n", w.get());
}
