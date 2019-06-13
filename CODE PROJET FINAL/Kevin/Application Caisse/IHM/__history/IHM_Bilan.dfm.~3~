object Form_Bilan: TForm_Bilan
  Left = 0
  Top = 0
  Caption = 'Bilan des ventes'
  ClientHeight = 142
  ClientWidth = 412
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label_Periode: TLabel
    Left = 56
    Top = 78
    Width = 95
    Height = 13
    Caption = '* Champ obligatoire'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label_Avertissement: TLabel
    Left = 16
    Top = 16
    Width = 374
    Height = 14
    Caption = 
      'Pensez '#224' sauvegarder l'#39'ancien bilan des ventes, celui-ci le supp' +
      'rimera'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ComboBox_Periode: TComboBox
    Left = 48
    Top = 51
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'P'#233'riode de vente'
    Items.Strings = (
      'Jour'
      'Semaine'
      'Mois'
      'Ann'#233'e')
  end
  object ComboBox_Medicament: TComboBox
    Left = 218
    Top = 51
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'M'#233'dicament'
    Items.Strings = (
      'M'#233'dicament')
  end
  object Bouton_Telecharger: TButton
    Left = 218
    Top = 99
    Width = 145
    Height = 25
    Caption = 'T'#233'l'#233'charger'
    TabOrder = 2
    OnClick = Bouton_TelechargerClick
  end
  object f: TFDConnection
    Params.Strings = (
      'Database=pharmacie'
      'User_Name=pharma'
      'Password=pharma'
      'Server=192.168.64.111'
      'DriverID=MySQL')
    Left = 48
    Top = 98
  end
  object FDQuery1: TFDQuery
    Connection = f
    SQL.Strings = (
      'SELECT * FROM `Medicament` WHERE `Quantite_Restante`')
    Left = 80
    Top = 98
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 112
    Top = 98
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'Forms'
    Left = 144
    Top = 98
  end
end
