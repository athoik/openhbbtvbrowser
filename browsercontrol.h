#ifndef BROWSERCONTROL_H
#define BROWSERCONTROL_H

#include <QApplication>
#include <QLocalSocket>
#include <QObject>
#include <QSocketNotifier>

class BrowserWindow;

enum VirtualKey {
    // Based on CEA-2014-A CE-HTML Annex F
    VK_UNDEFINED = 0,
    VK_CANCEL = 3,
    VK_BACK_SPACE = 8,
    VK_TAB = 9,
    VK_CLEAR = 12,
    VK_ENTER = 13,
    VK_SHIFT = 16,
    VK_CONTROL = 17,
    VK_ALT = 18,
    VK_PAUSE = 19,
    VK_CAPS_LOCK = 20,
    VK_KANA = 21,
    VK_FINAL = 24,
    VK_KANJI = 25,
    VK_ESCAPE = 27,
    VK_CONVERT = 28,
    VK_NONCONVERT = 29,
    VK_ACCEPT = 30,
    VK_MODECHANGE = 31,
    VK_SPACE = 32,
    VK_PAGE_UP = 33,
    VK_PAGE_DOWN = 34,
    VK_END = 35,
    VK_HOME = 36,
    VK_LEFT = 37,
    VK_UP = 38,
    VK_RIGHT = 39,
    VK_DOWN = 40,
    VK_COMMA = 44,
    VK_PERIOD = 46,
    VK_SLASH = 47,
    VK_0 = 48,
    VK_1 = 49,
    VK_2 = 50,
    VK_3 = 51,
    VK_4 = 52,
    VK_5 = 53,
    VK_6 = 54,
    VK_7 = 55,
    VK_8 = 56,
    VK_9 = 57,
    VK_SEMICOLON = 59,
    VK_EQUALS = 61,
    VK_A = 65,
    VK_B = 66,
    VK_C = 67,
    VK_D = 68,
    VK_E = 69,
    VK_F = 70,
    VK_G = 71,
    VK_H = 72,
    VK_I = 73,
    VK_J = 74,
    VK_K = 75,
    VK_L = 76,
    VK_M = 77,
    VK_N = 78,
    VK_O = 79,
    VK_P = 80,
    VK_Q = 81,
    VK_R = 82,
    VK_S = 83,
    VK_T = 84,
    VK_U = 85,
    VK_V = 86,
    VK_W = 87,
    VK_X = 88,
    VK_Y = 89,
    VK_Z = 90,
    VK_OPEN_BRACKET = 91,
    VK_BACK_SLASH = 92,
    VK_CLOSE_BRACKET = 93,
    VK_NUMPAD0 = 96,
    VK_NUMPAD1 = 97,
    VK_NUMPAD2 = 98,
    VK_NUMPAD3 = 99,
    VK_NUMPAD4 = 100,
    VK_NUMPAD5 = 101,
    VK_NUMPAD6 = 102,
    VK_NUMPAD7 = 103,
    VK_NUMPAD8 = 104,
    VK_NUMPAD9 = 105,
    VK_MULTIPLY = 106,
    VK_ADD = 107,
    VK_SEPARATER = 108,
    VK_SUBTRACT = 109,
    VK_DECIMAL = 110,
    VK_DIVIDE = 111,
    VK_F1 = 112,
    VK_F2 = 113,
    VK_F3 = 114,
    VK_F4 = 115,
    VK_F5 = 116,
    VK_F6 = 117,
    VK_F7 = 118,
    VK_F8 = 119,
    VK_F9 = 120,
    VK_F10 = 121,
    VK_F11 = 122,
    VK_F12 = 123,
    VK_DELETE = 127,
    VK_NUM_LOCK = 144,
    VK_SCROLL_LOCK = 145,
    VK_PRINTSCREEN = 154,
    VK_INSERT = 155,
    VK_HELP = 156,
    VK_META = 157,
    VK_BACK_QUOTE = 192,
    VK_QUOTE = 222,
    VK_RED = 403,
    VK_GREEN = 404,
    VK_YELLOW = 405,
    VK_BLUE = 406,
    VK_GREY = 407,
    VK_BROWN = 408,
    VK_POWER = 409,
    VK_DIMMER = 410,
    VK_WINK = 411,
    VK_REWIND = 412,
    VK_STOP = 413,
    VK_EJECT_TOGGLE = 414,
    VK_PLAY = 415,
    VK_RECORD = 416,
    VK_FAST_FWD = 417,
    VK_PLAY_SPEED_UP = 418,
    VK_PLAY_SPEED_DOWN = 419,
    VK_PLAY_SPEED_RESET = 420,
    VK_RECORD_SPEED_NEXT = 421,
    VK_GO_TO_START = 422,
    VK_GO_TO_END = 423,
    VK_PREV = 424,
    VK_NEXT = 425,
    VK_RANDOM_TOGGLE = 426,
    VK_CHANNEL_UP = 427,
    VK_CHANNEL_DOWN = 428,
    VK_STORE_FAVORITE_0 = 429,
    VK_STORE_FAVORITE_1 = 430,
    VK_STORE_FAVORITE_2 = 431,
    VK_STORE_FAVORITE_3 = 432,
    VK_RECALL_FAVORITE_0 = 433,
    VK_RECALL_FAVORITE_1 = 434,
    VK_RECALL_FAVORITE_2 = 435,
    VK_RECALL_FAVORITE_3 = 436,
    VK_CLEAR_FAVORITE_0 = 437,
    VK_CLEAR_FAVORITE_1 = 438,
    VK_CLEAR_FAVORITE_2 = 439,
    VK_CLEAR_FAVORITE_3 = 440,
    VK_SCAN_CHANNELS_TOGGLE = 441,
    VK_PINP_TOGGLE = 442,
    VK_SPLIT_SCREEN_TOGGLE = 443,
    VK_DISPLAY_SWAP = 444,
    VK_SCREEN_MODE_NEXT = 445,
    VK_VIDEO_MODE_NEXT = 446,
    VK_VOLUME_UP = 447,
    VK_VOLUME_DOWN = 448,
    VK_MUTE = 449,
    VK_SURROUND_MODE_NEXT = 450,
    VK_BALANCE_RIGHT = 451,
    VK_BALANCE_LEFT = 452,
    VK_FADER_FRONT = 453,
    VK_FADER_REAR = 454,
    VK_BASS_BOOST_UP = 455,
    VK_BASS_BOOST_DOWN = 456,
    VK_INFO = 457,
    VK_GUIDE = 458,
    VK_TELETEXT = 459,
    VK_SUBTITLE = 460,
    VK_BACK = 461,
    VK_MENU = 462,
};

#if defined(EMBEDDED_BUILD)

struct input_event {
    long pad1;
    long pad2;
    quint16 type;
    quint16 code;
    qint32 value;
};
#define KEY_1			2
#define KEY_2			3
#define KEY_3			4
#define KEY_4			5
#define KEY_5			6
#define KEY_6			7
#define KEY_7			8
#define KEY_8			9
#define KEY_9			10
#define KEY_0			11
#define KEY_UP			103
#define KEY_LEFT		105
#define KEY_RIGHT		106
#define KEY_DOWN		108
#define KEY_MUTE		113
#define KEY_VOLUMEDOWN	114
#define KEY_VOLUMEUP	115
#define KEY_POWER		116
#define KEY_PAUSE		119
#define KEY_STOP		128
#define KEY_MENU		139
#define KEY_REWIND		168
#define KEY_EXIT		174
#define KEY_PLAY		207
#define KEY_FASTFORWARD	208
#define KEY_OK			0x160
#define KEY_RED			0x18e
#define KEY_GREEN		0x18f
#define KEY_YELLOW		0x190
#define KEY_BLUE		0x191

class RemoteController : public QObject
{
    Q_OBJECT

public:
    RemoteController(const QString &device = QString("/dev/input/event0"));
    ~RemoteController();

Q_SIGNALS:
    void activate(const int &keyCode);

protected Q_SLOTS:
    void readKeycode();

protected:
    void volumeMute();
    void volumeDown();
    void volumeUp();

private:
    int m_fd;
    QSocketNotifier *m_notify;
    bool m_muteToggle;
};

#endif

class WindowEventFilter : public QObject
{
    Q_OBJECT

public:
    WindowEventFilter(QObject *parent = Q_NULLPTR);

Q_SIGNALS:
    void activate(const int &keyCode);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

class CommandClient : public QObject
{
    Q_OBJECT

public:
    enum BrowserCommand {
        CommandBroadcastPlay = 1,
        CommandBroadcastStop = 2,
    };

    CommandClient(const QString &sockFile = QString("/tmp/openhbbtvbrowser.socket"));
    bool writeCommand(int command);
    bool writeCommand(int command, const QString &data);

protected Q_SLOTS:
    void readCommand();

private:
    QLocalSocket *m_socket;
};

#endif // BROWSERCONTROL_H
