object Ordonnance: TOrdonnance
  Left = 0
  Top = 0
  Caption = 'Ordonnance'
  ClientHeight = 636
  ClientWidth = 443
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label_Medicaments: TLabel
    Left = 24
    Top = 24
    Width = 62
    Height = 13
    Caption = 'M'#233'dicaments'
  end
  object Label_Quantite: TLabel
    Left = 223
    Top = 24
    Width = 42
    Height = 13
    Caption = 'Quantit'#233
  end
  object ComboBox_Medicaments: TComboBox
    Left = 24
    Top = 56
    Width = 177
    Height = 21
    TabOrder = 0
  end
  object Bouton_OK: TButton
    Left = 344
    Top = 54
    Width = 49
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Bouton_OKClick
  end
  object Edit_Quantite: TEdit
    Left = 223
    Top = 56
    Width = 81
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object StringGrid_Ordonnance: TStringGrid
    Left = 24
    Top = 104
    Width = 304
    Height = 457
    ColCount = 2
    DefaultColWidth = 200
    RowCount = 1
    FixedRows = 0
    TabOrder = 3
    RowHeights = (
      24)
  end
  object Bouton_Supprimer: TButton
    Left = 344
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Supprimer'
    TabOrder = 4
    OnClick = Bouton_SupprimerClick
  end
  object Bouton_Valider: TButton
    Left = 344
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Valider'
    TabOrder = 5
    OnClick = Bouton_ValiderClick
  end
  object f: TFDConnection
    Params.Strings = (
      'Database=pharmacie'
      'User_Name=pharma'
      'Password=pharma'
      'Server=192.168.64.111'
      'DriverID=MySQL')
    Left = 24
    Top = 584
  end
  object FDQuery1: TFDQuery
    Connection = f
    SQL.Strings = (
      'SELECT * FROM `Medicament` WHERE `Quantite_Restante` != 0')
    Left = 88
    Top = 584
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 152
    Top = 584
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'Forms'
    Left = 216
    Top = 584
  end
end
