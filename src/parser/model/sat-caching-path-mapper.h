/*
// Copyright (c) 2015 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/
#ifndef SAT_CACHING_PATH_MAPPER_H
#define SAT_CACHING_PATH_MAPPER_H

#include "sat-path-mapper.h"
#include <map>

namespace sat {

using namespace std;

class caching_path_mapper : public path_mapper {
public:
    explicit caching_path_mapper(const string& cache_dir_path);
    ~caching_path_mapper();
    void open();
    void close();

    bool find_file(const string& target_path,
                   string&       host_path,
                   string&       sym_path) const override;

protected:
    virtual bool get_host_path(const string& target_path,
                               string&       host_path,
                               string&       sym_path) const = 0;

private:
    bool resolve_host_path(const string& target_path, string& host_path, string& sym_path) const;

    mutable map<string, pair<string, string>> ram_cache_;
    FILE*                                     file_cache_;
    string                                    cache_dir_path_;
}; // caching_path_mapper

} // sat

#endif // SAT_CACHING_PATH_MAPPER_H
