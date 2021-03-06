/*
 * Copyright (C) 2014-2015  Mozilla Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#if ANDROID_VERSION >= 18

#include <hardware/bluetooth.h>

struct pdu;
struct pdu_wbuf;

bt_status_t
(*register_bt_rc(unsigned char mode, unsigned long max_num_clients,
                 void (*send_pdu_cb)(struct pdu_wbuf*)))(const struct pdu*);

int
unregister_bt_rc(void);

#else

#define register_bt_rc  NULL
#define unregister_bt_rc  NULL

#endif
