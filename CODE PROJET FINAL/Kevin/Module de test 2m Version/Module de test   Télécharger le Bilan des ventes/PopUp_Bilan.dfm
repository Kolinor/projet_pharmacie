object Form_PopUp: TForm_PopUp
  Left = 0
  Top = 0
  Caption = 'Confirmation'
  ClientHeight = 126
  ClientWidth = 444
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 27
    Top = 16
    Width = 396
    Height = 18
    Caption = 'Voulez-vous vraiment t'#233'l'#233'charger le bilan des ventes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 43
    Top = 40
    Width = 360
    Height = 13
    Caption = 
      'Celui-ci supprimera l'#39'ancien bilan des ventes, pensez donc '#224' le ' +
      'sauvegarder'
  end
  object Bouton_Oui: TButton
    Left = 96
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Oui'
    TabOrder = 0
  end
  object Bouton_Non: TButton
    Left = 264
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Non'
    TabOrder = 1
  end
end
