//
//  digitalConverter.m
//  finalProject
//
//  Created by Bader Al-Mal on 04/12/2012.
//  Copyright (c) 2012 Bader Al-Mal. All rights reserved.
//
// this class contains the methods and functions to convert binar and decimal numbers

#import "digitalConverter.h"

@interface digitalConverter ()

@end

@implementation digitalConverter


- (void)viewDidLoad
{
    [super viewDidLoad];

    [self initUI];

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


- (IBAction)textField2:(UITextField *)sender {
    
    [self decimalConv]; // call the method to convert decimal numbers when enter is pressed

}

- (IBAction)textField1:(UITextField *)sender {
    
    [self binaryConv]; // call the method to convert binary numbers when enter is pressed

}



#pragma mark - converting methods

- (int) binaryConv; { // converts binary values entered to decimal and hexadecimal
    
    int j=1;
    decimalValue = 0;
    binaryValue = [self.valueEntered intValue];
    
    while(binaryValue!=0){ // while the value entered doesnt equal to zero
        
        
        
        remainder = binaryValue % 10;
        
        decimalValue = decimalValue + remainder * j;
        
        j = j * 2;
        
        binaryValue=binaryValue/10;
        
        // binary is base 2 so what we do is multiply each digit by j = 1,2,3.. and then add them together to get the decimal value
        
        
    }
    
    // in order to display the hexadecimal value we use %X which converts the decimal value to the equivelant hexadecimal value
    self.hexaText.text = [[NSString alloc]initWithFormat:@"%lX",decimalValue]; 

    
    self.decimalText.text = [[NSString alloc]initWithFormat:@"%ld",decimalValue];
    
    return 0;
}

- (int)decimalConv; { // converts decimal values entered to binary and hexadecimal
    
    
   
    NSString *outputValue; // creating a string to store the value in it
    outputValue=@""; // initialize the string
    
    decimalValue = [self.valueEntered2 intValue];

    NSString *dec = self.valueEntered2; // getting and storing the value for the hexadecimal in a string
    
    
    NSString *hex = [NSString stringWithFormat:@"%X", [dec integerValue]]; // using %X to convert the value to hexadecimal
    
    
    
    while (decimalValue!=0) {
        
        remainder = decimalValue % 2; // we find the remainder
        
        decimalValue = (decimalValue) / 2; // we keep deviding the quotient by 2 until we get zero
        
        outputValue=[NSString stringWithFormat:@"%i%@", remainder, outputValue]; // everytime we divide we store the value in a string until the loop ends, this way we get an array

        
    }
    
    
    self.binaryText.text = [[NSString alloc]initWithFormat:@"%@",outputValue];
    
    self.hexaText.text = [[NSString alloc]initWithFormat:@"%@",hex];
    
    return 0;
}

#pragma mark - hide keyboard

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    
    
    self.valueEntered = self.binaryText.text;
    
    self.valueEntered2 = self.decimalText.text;
    
    self.valueEntered3 = self.hexaText.text;
    
    
    
    if (textField == self.binaryText) {
        [textField resignFirstResponder];   }
    
    else {
        [textField resignFirstResponder];
    }
    
    
    return YES;
    
}

# pragma mark - initialisation methods

- (IBAction)clearButton:(UIButton *)sender  {
    
    // resets the textField
    
    self.binaryText.text = @" ";
    self.decimalText.text = @" ";
    self.hexaText.text = @" ";
    
}

-(void) initUI; {
    
    self.navigationItem.title = @"Number Base Converter"; // set the title
    self.binaryText.delegate = self;
    self.decimalText.delegate = self;
    self.hexaText.delegate = self;
    
  
    
    self.binaryLabel.text = @"Binary";
    self.decimalLabel.text = @"Decimal";
    self.hexaLabel.text = @"Hexadecimal";
    self.noticeLabel.text = @"*Note: Unfortunatly at the mean time you cant convert from hexadecimal to binary nor decimal, but we will include it in future updates, we apologise for any inconvience";
    
    self.binaryLabel.textColor = [UIColor whiteColor];
    self.decimalLabel.textColor = [UIColor whiteColor];
    self.hexaLabel.textColor = [UIColor whiteColor];
    self.noticeLabel.textColor = [UIColor whiteColor];
    self.hexaText.backgroundColor = [UIColor lightGrayColor];
    self.view.backgroundColor = [UIColor blackColor];
    
}

@end
