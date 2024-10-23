#include <cstdint>
#include <vector>

// Performs element-wise vector addition for `n` elements on the GPU.
// y = x1 + x2
auto vec_add_gpu(
    std::vector<int32_t>& y,
    std::vector<int32_t> const& x1,
    std::vector<int32_t> const& x2,
    std::size_t n) -> void {
        if (cudaMalloc()
    }