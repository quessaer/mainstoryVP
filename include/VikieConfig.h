//
//  VikieConfig.h
//  VikieNative
//
//  Created by yettie on 2021/03/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface VikieConfig : NSObject

typedef enum{
    number,
    qwerty,
    pattern
}KeypadType;

/**
 * @property keypadType
 * @brief 키패드 타입
 */
@property KeypadType keypadType;
/**
 * @property forTabMode
 * @brief TabMode 사용시 나타날 좌표 값.
 */
@property CGPoint forTabMode;

/**
 * @property titleDisplay
 * @brief titleBar 유무(default true)
 */
@property BOOL titleDisplay;

/**
 * @property easyReadability
 * @brief keyPad 순서대로 보여주는 option(default true)
 */
@property BOOL easyReadability;

/**
 * @property tabMode
 * @brief  tabMode 유무(default false)
 */
@property BOOL tabMode;

/**
 * @property initValueRearrange
 * @brief   재 배열시 기존에 입력한 값 초기화 여부(default true)
 */
@property BOOL initValueRearrange;

/**
 * @property figureLimitation
 * @brief   keyPad 입력 최대 길이 설정(default -1. 없음.)
 */
@property int figureLimitation;

/**
 * @property convertKeyOptionInterval
 * @brief   키값 치환 옵션
 */
@property int convertKeyInterval;

@end

NS_ASSUME_NONNULL_END
