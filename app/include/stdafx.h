#pragma once

//
// C/C++
//
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <atomic>
#include <memory>
#include <utility>
#include <cassert>
#include <functional>
#include <optional>
#include <sstream>
#include <csignal>
#include <limits>
#include <fstream>

//
// Qt
//
#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QtWidgets/QMainWindow>
#include <QStyledItemDelegate>
#include <QApplication>

using namespace std::chrono_literals;
using std::size_t;

#define theApp static_cast<Application*>(Application::instance())