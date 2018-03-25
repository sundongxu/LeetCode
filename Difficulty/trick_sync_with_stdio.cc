// 涨知识的sync_with_stdio! 提升效率惊人！
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false); // 禁用cin和cout的缓冲机制
    // untie cin & cout
    cin.tie(NULL); // 解除cin与cout的绑定
    return 0;
}();