/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef T_SET_H
#define T_SET_H

#include "thrift/parse/t_container.h"

/**
 * A set is a lightweight container type that just wraps another data type.
 *
 */
class t_set : public t_container {
public:
  t_set(t_type* elem_type) : elem_type_(elem_type) {}

  const t_type* get_elem_type() const { return elem_type_; }

  t_type* get_elem_type() { return elem_type_; }

  bool is_set() const override { return true; }

  void validate() const {
#ifndef ALLOW_EXCEPTIONS_AS_TYPE
    if( get_elem_type()->get_true_type()->is_xception()) {
      failure("exception type \"%s\" cannot be used inside a set", get_elem_type()->get_name().c_str());
    }
#endif
  }

private:
  t_type* elem_type_;
};

#endif
