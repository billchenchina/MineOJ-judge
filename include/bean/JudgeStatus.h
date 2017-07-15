/*
 * @file    JudgeStatus.h
 * @brief   JudgeStatus 枚举
 * @author  billchenchina
 * @date    2017年7月15日
 *
 */

#ifndef BEAN_JUDGESTATUS_H_
#define BEAN_JUDGESTATUS_H_


namespace MineOJ{

/* @enum    MineOJ::JudgeStatus
 * @author  billchenchina
 * @date    2017年7月15日
*/
enum JusgeStatus{
    /*
     * Accepted - 成功通过评测
     */
    AC = 0,
    /*
     * Wrong Answer - 答案错误
     */
    WA = 1,
    /*
     * Runtime Error - 运行时错误
     */
    RE = 2,
    /*
     * Memory Limit Exceeded - 内存超出限制
     */
    MLE = 3,
    /*
     * Time Limit Exceeded - 时间超出限制
     */
    TLE = 4,
    /*
     * Output Limit Exceeded - 输出超出限制
     */
    OLE = 5,
    /*
     * Dangerous Syscalls - 危险的系统调用
     */
    DGS = 6,
    /*
     * Judgement Failed - 评测出现错误
     */
    JGF = 7,
    /*
     * Special Judge Accepted -特殊评测下成功通过评测
     */
    SPJ_AC = 1000,
    /*
     * Special Judge Wrong Answer - 特殊评测下答案错误
     */
    SPJ_WA = 1001,
    /*
     * Special Judge Runtime Error - 特殊评测下运行时错误
     */
    SPJ_RE = 2,
    /*
     * Special Judge Memory Limit Exceeded - 特殊评测下内存超出限制
     */
    SPJ_MLE = 3,
    /*
     * Special Judge Time Limit Exceeded - 特殊评测下时间超出限制
     */
    SPJ_TLE = 4,
    /*
     * Special Judge Output Limit Exceeded - 特殊评测下输出超出限制
     */
    SPJ_OLE = 5,
    /*
     * Special Judge Dangerous Syscalls - 特殊评测下危险的系统调用
     */
    SPJ_DGS = 6,
    /*
     * Special Judge Judgement Failed - 特殊评测下评测出现错误
     */
    SPJ_JGF = 7

};
}


#endif /* BEAN_JUDGESTATUS_H_ */
