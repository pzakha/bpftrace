#pragma once

#include <tuple>
#include <string>
#include <vector>
#include <iostream>

namespace bpftrace {

typedef std::tuple<std::string, std::string> usdt_probe_pair;

class USDTHelper
{
public:
  static usdt_probe_pair find(void *ctx, int pid, std::string name);
};

struct DeprecatedName
{
  std::string old_name;
  std::string new_name;
  bool show_warning = true;
};

static std::vector<DeprecatedName> DEPRECATED_LIST =
{
  { "stack", "kstack"},
  { "sym", "ksym"},
};


bool has_wildcard(const std::string &str);
std::vector<int> get_online_cpus();
std::vector<int> get_possible_cpus();
std::vector<std::string> get_kernel_cflags(
    const char* uname_machine,
    const std::string& ksrc,
    const std::string& kobj);
std::string is_deprecated(std::string &str);
std::string exec_system(const char* cmd);
std::string resolve_binary_path(const std::string& cmd);

} // namespace bpftrace
