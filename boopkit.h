// Copyright © 2022 Kris Nóva <kris@nivenly.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// ███╗   ██╗ ██████╗ ██╗   ██╗ █████╗
// ████╗  ██║██╔═████╗██║   ██║██╔══██╗
// ██╔██╗ ██║██║██╔██║██║   ██║███████║
// ██║╚██╗██║████╔╝██║╚██╗ ██╔╝██╔══██║
// ██║ ╚████║╚██████╔╝ ╚████╔╝ ██║  ██║
// ╚═╝  ╚═══╝ ╚═════╝   ╚═══╝  ╚═╝  ╚═╝
//

#ifndef BOOPKIT_BOOPKIT_H
#define BOOPKIT_BOOPKIT_H

// tcp_return
//
// This is the "protocol" that allows us to begin building
// the RCE back against a client.
//
// This should be kept as small as possible as we will need
// to craft this structure for every probe we use to try to
// boop with.
//
// In other words, if we can get 4 octets of "saddr" information
// we can pwn your shit.
struct tcp_return {
  __u8 saddr[4];
};

// SPDX-License-Identifier: BSD-3-Clause
#define MAXPIDLEN 10
#define PROG_00 0
#define PROG_01 1
#define PROG_02 2

#define FILENAME_LEN_MAX 50
#define TEXT_LEN_MAX 20

#define TASK_COMM_LEN 16
struct event {
  int pid;
  char comm[TASK_COMM_LEN];
  bool success;
};

struct tr_file {
  char filename[FILENAME_LEN_MAX];
  unsigned int filename_len;
};

struct tr_text {
  char text[TEXT_LEN_MAX];
  unsigned int text_len;
};

#endif  // BOOPKIT_BOOPKIT_H