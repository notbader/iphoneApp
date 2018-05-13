//
//  getColor.m
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//
// this class is used to get the color from the value entered by the user

#import "getColor.h"

@interface getColor ()

@end

@implementation getColor
@synthesize valueEntered = _valueEntered;
@synthesize colorData = _ColorData;
@synthesize colorData1 = _ColorData1;
@synthesize colorData2 = _ColorData2;
@synthesize secondValue = _secondValue;
@synthesize thirdValue  = _thirdValue;

- (void)viewDidLoad
{
    
    [self initUI];
    
    // setting the arrays
    
    _ColorData = [[NSArray alloc]initWithObjects:
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Black.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Brown.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Red.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Orange.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Yellow.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Green.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Blue.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"violet.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Grey.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"White.png"]], nil ];
    
    
    _ColorData1 =[[NSArray alloc]initWithObjects:
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Black.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Brown.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Red.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Orange.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Yellow.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Green.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Blue.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"violet.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Grey.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"White.png"]], nil ];
    
    
    _ColorData2 =[[NSArray alloc]initWithObjects:
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Black.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Brown.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Red.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Orange.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Yellow.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Green.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Blue.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"violet.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Grey.png"]],
                  [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"White.png"]], nil ];

        _lastBand = [[NSArray alloc]initWithObjects:
                 [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Gold.png"]],
                 [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Silver copy.png"]],
                 [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"None.png"]], nil ];
    [super viewDidLoad];
    

    
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - datasource methods

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 4;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    
    if (component == 3) {
        
        return _lastBand.count;
        
    }
    
    else    {
        return _ColorData.count;
        
    }
}

#pragma mark - delegate methods

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    
    
    if (component == 3) {
        
        return [_lastBand objectAtIndex:row];
        
    }
    
    else    {
        return [_ColorData objectAtIndex:row];
        
    }
    
}

- (UIView *) pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view
{
    
    if (component == 0)
    {
        return [_ColorData objectAtIndex:row];
        
    }
    
    else if (component == 1)    {
        return [_ColorData1 objectAtIndex:row];
        
    }
    
    else if (component == 2)    {
        
        return [_ColorData2 objectAtIndex:row];
        
    }
    
    else {
        
        return [_lastBand objectAtIndex:row];
    }
    return 0;
}

#pragma mark - getting the color


- (IBAction)buttonPressed:(id)sender {
    
        [self getColor]; // calling the method to find the color
        [self findTolerence];

    }

-(void)getColor;    {
    
    
    double code = [self.valueEntered intValue]; // the input is stored in the variable double code
    double remainder = fmod(code,10); // used to find the remainder of the input value, this will give us the value of the second band
    double multi = [self.secondValue intValue];
    
    int i = 0, j = 0;
    
    
    while (code >= 10) { // while the input is bigger or equal to ten
        
        i++; 
        
        code = code - 10; // we subtract 10 from the code and count how many times this step is repeated ( i++ )
        
        [self.myPicker selectRow:i inComponent:0 animated:YES]; // used to display the color of the 1st figure
        [self.myPicker selectRow:remainder inComponent:1 animated:YES]; // used to display the color of the 2nd figure
        
    }
    
    while (multi >= 10)    { // while the multiplier entered is bigger than 10
        
        multi = multi / 10; // we divide by ten and count how many times this is done
        
        j++;
        
        
        [self.myPicker selectRow:j inComponent:2 animated:YES]; // display the result in picker view

    }
    
    }


-(void) findTolerence;  {
    
    double tolerence = [self.thirdValue intValue];

    tolerence = tolerence / 5;
    
    if ( tolerence == 4)  {
        
        [self.myPicker selectRow:2 inComponent:3 animated:YES];    }
    
    else if (tolerence == 2)   {
        
        [self.myPicker selectRow:1 inComponent:3 animated:YES];
        
    }
    
    else {
        
        [self.myPicker selectRow:0 inComponent:3 animated:YES];     }
    
}



#pragma mark - hiding keyboard


- (BOOL)textFieldShouldReturn:(UITextField *)textField {
        
        self.valueEntered = self.myText.text;
        self.secondValue = self.myText2.text;
        self.thirdValue = self.myText3.text;
    
        
        if (textField == self.myText) {
            [textField resignFirstResponder];   }
        
        else {
            [textField resignFirstResponder];
        }
        
        
        return YES;
        
}

#pragma mark - initialisation methods

- (IBAction)resetButton:(UIButton *)sender {
    
    self.myText2.text = @" ";
    self.myText.text = @" ";
    
    [self.myPicker selectRow:0 inComponent:0 animated:YES];
    [self.myPicker selectRow:0 inComponent:1 animated:YES];
    [self.myPicker selectRow:0 inComponent:2 animated:YES];
}


-(void) initUI; {
    self.navigationItem.title = @"Value To Code"; // set the title
    self.myText2.delegate = self;
    self.myText.delegate = self;
    self.myText3.delegate = self;

    self.myLabel.text = @" Value ";
    self.myLabel2.text = @" Multiplier ";
    self.myLabel3.text = @" Tolerence ";

    self.view.backgroundColor = [UIColor blackColor];
    self.myLabel.textColor = [UIColor whiteColor];
    self.myLabel2.textColor = [UIColor whiteColor];
   self.myLabel3.textColor = [UIColor whiteColor];
    
}




@end
