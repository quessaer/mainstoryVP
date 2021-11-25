//
//  VikieError.h
//  VikieNative
//
//  Created by yettie on 2021/03/25.
//

#import <Foundation/Foundation.h>
#define _VIKIE_NATIVE_ERROR_H__ @"com.VikieNative-code.VikieErrorCode"

NS_ASSUME_NONNULL_BEGIN

@interface VikieError : NSError

typedef enum{
   
    SUCCESS                                 = 0,
    VIKIE_ERROR_INVALID_INPUT               = -7000,    /**< -7000 - 입력값이 nil이거나 길이가 0*/
    VIKIE_ERROR_ILLEGEL_STATUS              = -7001,    /**< -7001 - 순서 오류 */
    VIKIE_ERROR_LOAD_IMAGE_FAILD            = -7002,    /**< -7002 - Bundle에서 이미지 추출 실패 */
    VIKIE_ERROR_BAD_IMAGE_DATA              = -7003,    /**< -7003 - 유효하지 않은 Image*/
    VIKIE_ERROR_FAIL_TO_ENCRYPT             = -7004,    /**< -7004 - 암호화 실패*/
    VIKIE_ERROR_FAIL_TO_DECRYPT             = -7005,    /**< -7005 - 복호화 실패*/
    VIKIE_ERROR_ALREADY_ATTACH              = -7006,    /**< -7006 - 키패드가 이미 띄워져 있음*/
    VIKIE_ERROR_FAIL_TO_MEMORY_ALLOCATE     = -7007,    /**< -7007 - 메모리 할당 에러*/
}VikieErrorCode;

+(NSError *)errorWithVikieNativeErrorCode:(NSInteger)code
                     localizedDescription:(NSString *)localizedDescription;

@end

NS_ASSUME_NONNULL_END
