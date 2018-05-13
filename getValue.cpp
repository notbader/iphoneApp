//
//  getValue.m
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//
// this class contains methods to show the value of a resistor color code, a UIPicker was used to display the image

#import "getValue.h"

@interface getValue ()

@end

@implementation getValue
@synthesize colorData = _ColorData;
@synthesize lastBand = _lastBand;
@synthesize colorData1 = _ColorData1;
@synthesize colorData2 = _ColorData2;


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    [self initUI];
    
    
    // declaring the arrays of images
    
    
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
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - datasource methods

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView{
    
    return 4;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component{
    
    if (component == 3) {
        
        return _lastBand.count;
        
    }
    
    else    {
        return _ColorData.count;
        
    }
}

#pragma mark - delegate methods

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component{
    
    if (component == 3) {
        
        return [_lastBand objectAtIndex:row];
        
    }
    
    else    {
        return [_ColorData objectAtIndex:row];
        
    }
}

- (UIView *) pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view
{
    // this method is used to view images at the appropriate row
    
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


- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    
    // in this method rows were assigned to their appropriate values e.g. first row = 0 so the first image will have value 0
    
    _firstFigure = [pickerView selectedRowInComponent:0];
    _secondFigure = [pickerView selectedRowInComponent:1];
    _tolerenceRow= [pickerView selectedRowInComponent:3];
    
    // assign value to the tolerence band
    
    if ( _tolerenceRow == 0)  {
        
        tolerence = 5;
    }
    
    else if (_tolerenceRow == 1)   {
        
        tolerence = 10;
    }
    
    else {
        
        tolerence = 20;
    }
     self.myText2.text = [[NSString alloc]initWithFormat:@" ±%i % ",tolerence]; // printing the value of tolerence
    
    switch (component) { // assiging the value for the multiplier band
        case 2:
            self.multiplier = pow(10,row);
            break;
        default:
            break;
    }
    
[self calcValue]; // calling method to calculate the value of the color band

    }




#pragma mark - calculate value

-(void) calcValue;   { // method to calculate the value of the band
    
    
    float value;
    
    if (_multiplier == 0)   {
        
        value = (self.firstFigure *10 + self.secondFigure);
        
        // if the first multiplier was selected we will just multiply the first band with the second
        
        self.myText.text = [[NSString alloc]initWithFormat:@" %.0f Ω",value];
        
        
    }
    
    else {
        
        value = (self.firstFigure *10 + self.secondFigure)* _multiplier; // for multipliers bigger than zero we multiply the first two bands with the multiplier
        
    }
    
    // the condition statement was used to print values with units
    
    if ( value >= 10000000000)   {
        
        value = value/1000000000; // to get rid of the zeros
        
        self.myText.text = [[NSString alloc]initWithFormat:@"%.0f GΩ ",value];
        
    }
    
    else if ( value >= 10000000){
        
        value = value/1000000;
        
        self.myText.text = [[NSString alloc]initWithFormat:@"%.0f MΩ  ",value];
    }
    
    
    else  if ( value >= 10000) {
        
        value = value / 1000;
        
        self.myText.text = [[NSString alloc]initWithFormat:@"%.0f KΩ",value];
        
        
    }
    
    else {
        
        self.myText.text = [[NSString alloc]initWithFormat:@"%.0f Ω ",value];
        
        
    }
    
}

#pragma mark - initialisation methods

- (IBAction)resetButton:(id)sender {
    
    // ressting the picker view by selecting row "0" and text field
    
    self.myText.text = @" ";
    self.myText2.text = @" ";
    [self.myPicker selectRow:0 inComponent:0 animated:YES];
    [self.myPicker selectRow:0 inComponent:1 animated:YES];
    [self.myPicker selectRow:0 inComponent:2 animated:YES];
    [self.myPicker selectRow:0 inComponent:3 animated:YES];
    
  

    
    
}


-(void) initUI; {
    
    self.title = @"Code To Value";
    
    self.myLabel.text = @" Resistance : ";
    self.myLabel2.text = @" Tolerance : ";
    
    self.myText.backgroundColor = [UIColor lightGrayColor];
    self.myText2.backgroundColor = [UIColor lightGrayColor];
    
    self.myLabel.textColor = [UIColor whiteColor];
    self.myLabel2.textColor = [UIColor whiteColor];
    
    
    self.view.backgroundColor = [UIColor blackColor];
    

}

@end
