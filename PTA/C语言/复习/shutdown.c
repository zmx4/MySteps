#include <windows.h>
#include <stdlib.h>

int main() {
    // 创建一个确认对话框
    int result = MessageBox(NULL, "确定要关闭计算机吗？", "确认关机", MB_YESNO | MB_ICONQUESTION);

    if (result == IDYES) {
        // 用户选择了“是”，执行关机命令
        system("shutdown /s /f /t 0");
    } else {
        // 用户选择了“否”，不做任何操作
        MessageBox(NULL, "关机已取消。", "通知", MB_OK | MB_ICONINFORMATION);
    }

    return 0;
}