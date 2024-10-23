#include <cuda_runtime.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

constexpr double MEGABYTE{1048576.0};

auto main() -> int {
  std::printf("Checking CUDA device properties...\n");

  int device_count{};
  cudaError_t error = cudaGetDeviceCount(&device_count);
  if (error != cudaSuccess) {
    std::printf("Failed to query device count: CUDA error code %d\n", error);
  }
  std::printf("Found %d CUDA capable devices.\n", device_count);

  int device_id{};
  int driver_version{};
  int runtime_version{};

  for (device_id = 0; device_id < device_count; ++device_id) {
    cudaSetDevice(device_id);
    cudaDeviceProp device_properties{};
    cudaError_t error = cudaGetDeviceProperties(&device_properties, device_id);
    if (error != cudaSuccess) {
      std::printf(
          "Failed to query device properties for device id %d: CUDA error code %d\n",
          device_id,
          error);
    }
    std::printf("Device %d: \"%s\"\n", device_id, device_properties.name);
    double total_global_memory_megabytes{
        static_cast<double>(device_properties.totalGlobalMem) / MEGABYTE};
    printf("Total Global Memory: %f MB\n", total_global_memory_megabytes);
  }

  return EXIT_SUCCESS;
}