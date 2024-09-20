#include <cstdint>
#include <cstdlib>
#include <memory>
#include <random>
#include <vector>

// Returns a vector of random values.
std::vector<int8_t> generate_random_vector(std::size_t n) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int8_t> random_int8_t(INT8_MIN, INT8_MAX);

  auto v = std::vector<int8_t>();
  v.reserve(n);
  for (std::size_t i = 0; i < n; i++) {
    v[i] = random_int8_t(gen);
  }

  return v;
}

// Performs element-wise vector addition for `n` elements.
// y = x1 + x2
void vec_add_cpu(std::vector<int8_t> &y, std::vector<int8_t> const &x1,
                 std::vector<int8_t> const &x2, const std::size_t n) {
  for (std::size_t i = 0; i < n; i++) {
    y[i] = x1[i] + x2[i];
  }
}

int main() {
  printf("Starting vec_add_cpu\n");
  constexpr std::size_t N = 1 << 4;

  printf("Initializing input vectors...\n");
  const auto x1 = generate_random_vector(N);
  for (std::size_t i = 0; i < N; i++) {
    printf("%d, ", x1[i]);
  }
  printf("\n");
  const auto x2 = generate_random_vector(N);
  for (std::size_t i = 0; i < N; i++) {
    printf("%d, ", x2[i]);
  }
  printf("\n");

  printf("Initializing output vector...\n");
  auto y = std::vector<int8_t>();
  y.reserve(N);

  printf("Executing kernel...\n");
  vec_add_cpu(y, x1, x2, N);

  printf("Checking results of kernel...\n");
  for (std::size_t i = 0; i < N; i++) {
    printf("%d, ", y[i]);
  }
  printf("\n");

  printf("Exiting.\n");
  return 0;
}