//
//  getColor.h
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface getColor : UIViewController <UIPickerViewDelegate,UIPickerViewDataSource,UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet UILabel *myLabel3;
@property (strong, nonatomic) IBOutlet UITextField *myText3;
- (IBAction)resetButton:(UIButton *)sender;

- (IBAction)buttonPressed:(id)sender;
@property (strong, nonatomic) IBOutlet UIPickerView *myPicker;
@property (strong, nonatomic) IBOutlet UITextField *myText2;
@property (strong, nonatomic) IBOutlet UITextField *myText;
@property (strong, nonatomic) IBOutlet UILabel *myLabel;
@property (strong, nonatomic) IBOutlet UILabel *myLabel2;
@property double  multiplier;
@property (copy,nonatomic) NSString *valueEntered,*secondValue,*thirdValue;
@property (strong, nonatomic) NSArray *lastBand;
@property (strong,nonatomic) NSArray *colorData,*colorData1,*colorData2;

@end
