//
//  VikieNumber.h
//  VikieNative
//
//  Created by yettie on 2021/03/30.
//

#import <UIKit/UIKit.h>
#import "VikieConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface VikieNumber : UIView

#pragma mark - number

/**
 * @property numberStackViewArr
 * @brief keyPadView들이 담겨있는 Horizontal StackView (customizing 용도로 사용.)
 */
@property (nonatomic, weak) NSMutableArray<UIStackView *> *numberStackViewArr;

/**
 * @property numberKeyPadViewArr
 * @brief numberKeyPadViewArr에 속해 있는 keyPadView들 (customizing 용도로 사용.)
 */
@property (nonatomic, weak) NSMutableArray<UIView *> *numberKeyPadViewArr;

/**
 * @property numberbtnArr
 * @brief numberKeyPadViewArr들 안에 들어있는 button(숫자)들 (customizing 용도로 사용.)
 */
@property (nonatomic, weak) NSMutableArray<UIButton *> *numberbtnArr;

/**
 * @property numberBottomBtnArr
 * @brief numberKeyPadViewArr들 안에 들어있는 button(보안키패드 작동중, 삭제, 재배열, 입력완료)(customizing 용도로 사용.)
 */
@property (nonatomic, weak) NSMutableArray<UIButton *> *numberBottomBtnArr;

/**
 *  내부에서 사용하는 함수 (외부에서 사용 X)
 */
- (instancetype)init:(VikieConfig *)config;

/**
 *  내부에서 사용하는 함수 (외부에서 사용 X)
 */
- (int)createKeyPad;

/**
 *  내부에서 사용하는 함수 (외부에서 사용 X)
 */
- (void)clearKeyPadMemory;

@end


NS_ASSUME_NONNULL_END
