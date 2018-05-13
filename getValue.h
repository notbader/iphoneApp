//
//  getValue.h
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface getValue : UIViewController <UIPickerViewDelegate,UIPickerViewDataSource>

{
    int tolerence;
}
- (IBAction)resetButton:(id)sender;
@property (strong, nonatomic) IBOutlet UITextField *myText2;
@property (strong, nonatomic) IBOutlet UILabel *myLabel2;
@property (strong, nonatomic) IBOutlet UIPickerView *myPicker;
@property (strong, nonatomic) IBOutlet UITextField *myText;
@property (strong, nonatomic) IBOutlet UILabel *myLabel;
@property int firstFigure,secondFigure,tolerenceRow;
@property double multiplier;
@property (strong,nonatomic) NSArray *colorData,*colorData1,*colorData2;
@property (strong,nonatomic) NSArray *lastBand;

@end
