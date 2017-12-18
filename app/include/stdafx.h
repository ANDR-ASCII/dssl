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
#include <QThread>
#include <QWidget>
#include <QDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QHBoxLayout>
#include <QScreen>
#include <QDesktopWidget>
#include <QFrame>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QGLWidget>
#include <QDateTime>
#include <QPushButton>
#include <QPointer>

#include "common_macro_helpers.h"

#define theApp static_cast<Application*>(Application::instance())