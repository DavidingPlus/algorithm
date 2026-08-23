#ifndef LEETCODE_COMMON_GLOBALMACROS_H
#define LEETCODE_COMMON_GLOBALMACROS_H

// Keep platform-specific standard library selection in one repository-owned
// header so solution templates only need to include this file.
#if defined(_WIN32) || defined(_WIN64)
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#endif
