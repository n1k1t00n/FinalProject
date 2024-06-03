object Form1: TForm1
  Left = 0
  Top = 0
  ActiveControl = MainStringTree
  Caption = 'Form1'
  ClientHeight = 527
  ClientWidth = 766
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object SearchTimeResultLabel: TLabel
    Left = 631
    Top = 194
    Width = 10
    Height = 23
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object CountResultLabel: TLabel
    Left = 631
    Top = 166
    Width = 10
    Height = 23
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object FileFormatLabel: TLabel
    Left = 8
    Top = 14
    Width = 278
    Height = 19
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1085#1091#1078#1085#1099#1081' '#1090#1080#1087' '#1092#1072#1081#1083#1072' '#1076#1083#1103' '#1087#1086#1080#1089#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBackground
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object SearchTimeLabel: TLabel
    Left = 338
    Top = 199
    Width = 282
    Height = 22
    Caption = #1047#1072#1090#1088#1072#1095#1077#1085#1085#1086#1077' '#1074#1088#1077#1084#1103' '#1085#1072' '#1087#1086#1080#1089#1082' ('#1084#1089')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object CountLabel: TLabel
    Left = 339
    Top = 171
    Width = 247
    Height = 22
    Caption = #1050#1086#1083'-'#1074#1086' '#1085#1072#1081#1076#1077#1085#1085#1099#1093' '#1082#1083#1072#1089#1090#1077#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object DetectLabel: TLabel
    Left = 339
    Top = 137
    Width = 225
    Height = 28
    Caption = #1060#1072#1081#1083#1086#1074#1072#1103' '#1089#1080#1089#1090#1077#1084#1072' '#1076#1080#1089#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DetectResultLabel: TLabel
    Left = 599
    Top = 141
    Width = 77
    Height = 19
    Caption = 'Underfind'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DiskNameLabel: TLabel
    Left = 339
    Top = 8
    Width = 162
    Height = 22
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103' '#1076#1080#1089#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object SqlLabel: TLabel
    Left = 339
    Top = 46
    Width = 281
    Height = 20
    Caption = #1055#1088#1086#1087#1080#1096#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1083#1103' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103' '#1041#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 46
    Width = 278
    Height = 180
    TabOrder = 7
  end
  object Button3: TButton
    Left = 416
    Top = 266
    Width = 260
    Height = 85
    Caption = #1053#1072#1095#1072#1090#1100' '#1087#1086#1080#1089#1082' '#1082#1083#1072#1089#1090#1077#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button3Click
  end
  object MainStringTree: TVirtualStringTree
    Left = 8
    Top = 240
    Width = 381
    Height = 279
    ClipboardFormats.Strings = (
      'Plain text'
      'Unicode text')
    DefaultNodeHeight = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    Header.AutoSizeIndex = 0
    Header.Height = 23
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    ParentFont = False
    ScrollBarOptions.AlwaysVisible = True
    TabOrder = 1
    OnGetText = MainStringTreeGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 0
        Text = #1053#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072' '#1089#1080#1075#1085#1072#1090#1091#1088#1099
        Width = 195
      end
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible, coSmartResize, coAllowFocus, coEditable, coStyleColor]
        Position = 1
        Text = #1055#1077#1088#1074#1099#1077' 10 '#1073#1072#1081#1090' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 184
      end>
  end
  object ExeButton: TRadioButton
    Left = 27
    Top = 58
    Width = 78
    Height = 17
    Caption = '.exe'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    TabStop = True
  end
  object JpegButton: TRadioButton
    Left = 27
    Top = 81
    Width = 174
    Height = 30
    Caption = '.jpeg or .jpg'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object PngButton: TRadioButton
    Left = 27
    Top = 117
    Width = 78
    Height = 28
    Caption = '.png'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object PdfButton: TRadioButton
    Left = 27
    Top = 151
    Width = 78
    Height = 28
    Caption = '.pdf'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object StopButton: TButton
    Left = 416
    Top = 376
    Width = 260
    Height = 85
    Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1080#1089#1082' '#1082#1083#1072#1089#1090#1077#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = StopButtonClick
  end
  object Edit1: TEdit
    Left = 520
    Top = 8
    Width = 121
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBackground
    Font.Height = -15
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Text = '\\.\C:'
  end
  object Edit2: TEdit
    Left = 350
    Top = 82
    Width = 254
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    Text = '../../ClustersDB.sqlite3'
  end
  object BinButton: TRadioButton
    Left = 27
    Top = 185
    Width = 174
    Height = 17
    Caption = '.bin'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
end
