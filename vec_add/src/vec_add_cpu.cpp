#include <cstdint>
#include <vector>

// Performs element-wise vector addition for `n` elements on the CPU.
// y = x1 + x2
auto vec_add_cpu(
    std::vector<int32_t>& y,
    std::vector<int32_t> const& x1,
    std::vector<int32_t> const& x2,
    const std::size_t n) -> void {
  for (std::size_t i = 0; i < n; i++) {
    y[i] = x1[i] + x2[i];
  }
}
