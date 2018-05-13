//
//  digitalConverter.h
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface digitalConverter : UIViewController <UITextFieldDelegate>

{
    
    long int decimalValue,binaryValue,hexadecimalValue;
    int remainder;
}

- (IBAction)clearButton:(UIButton *)sender;
@property (strong, nonatomic) IBOutlet UITextField *hexaText;
@property (strong, nonatomic) IBOutlet UITextField *decimalText;
@property (strong, nonatomic) IBOutlet UITextField *binaryText;
@property (strong, nonatomic) IBOutlet UILabel *noticeLabel;
@property (strong, nonatomic) IBOutlet UILabel *hexaLabel;
@property (strong, nonatomic) IBOutlet UILabel *decimalLabel;
@property (strong, nonatomic) IBOutlet UILabel *binaryLabel;
@property NSString *valueEntered,*valueEntered2,*valueEntered3;

@end
